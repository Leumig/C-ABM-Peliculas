#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Movie.h"
#include "Validaciones.h"

eMovie *eMovie_new()
{
	eMovie *nuevaPelicula = (eMovie *)calloc(1, sizeof(eMovie));

	return nuevaPelicula;
}
eMovie *eMovie_newParametros(int id, char *titulo, int genero, float rating)
{
	eMovie *nuevaPelicula = eMovie_new();

	if (nuevaPelicula != NULL && id > 0 && titulo != NULL && genero >= 0 && genero <= 4 && rating >= 0 && rating <= 10)
	{
		if (!(eMovie_setId(nuevaPelicula, id) &&
					eMovie_setTitulo(nuevaPelicula, titulo) &&
					eMovie_setGenero(nuevaPelicula, genero) &&
					eMovie_setRating(nuevaPelicula, rating)))
		{
			eMovie_delete(nuevaPelicula);
			nuevaPelicula = NULL;
		}
	}
	return nuevaPelicula;
}

void eMovie_delete(eMovie *e)
{
	free(e);
}

int eMovie_setId(eMovie *e, int id)
{
	int todoOk = 0;
	if (e != NULL && id > 0)
	{
		e->id = id;
		todoOk = 1;
	}
	return todoOk;
}
int eMovie_getId(eMovie *e, int *id)
{
	int todoOk = 0;

	if (e != NULL && id != NULL)
	{
		*id = e->id;
		todoOk = 1;
	}

	return todoOk;
}
int eMovie_setTitulo(eMovie *e, char *titulo)
{
	int todoOk = 0;
	if (e != NULL && titulo != NULL && strlen(titulo) < 50 && strlen(titulo) > 1)
	{
		strcpy(e->titulo, titulo);
		strlwr(e->titulo);
		(e->titulo)[0] = toupper((e->titulo)[0]);

		todoOk = 1;
	}
	return todoOk;
}
int eMovie_getTitulo(eMovie *e, char *titulo)
{
	int todoOk = 0;

	if (e != NULL && titulo != NULL)
	{
		strcpy(titulo, e->titulo);
		todoOk = 1;
	}

	return todoOk;
}
int eMovie_setGenero(eMovie *e, int genero)
{
	int todoOk = 0;

	if (e != NULL && genero >= 0 && genero <= 4)
	{
		e->genero = genero;
		todoOk = 1;
	}

	return todoOk;
}
int eMovie_getGenero(eMovie *e, int *genero)
{
	int todoOk = 0;

	if (e != NULL && genero != NULL)
	{
		*genero = e->genero;
		todoOk = 1;
	}

	return todoOk;
}
int eMovie_getGeneroString(eMovie *e, char *genero)
{
	int todoOk = 0;

	if (e != NULL && genero != NULL)
	{
		switch (e->genero)
		{
		case 0:
			strcpy(genero, "Sin genero");
			break;
		case 1:
			strcpy(genero, "Drama");
			break;
		case 2:
			strcpy(genero, "Comedia");
			break;
		case 3:
			strcpy(genero, "Accion");
			break;
		default:
			strcpy(genero, "Terror");
			break;
		}

		todoOk = 1;
	}

	return todoOk;
}
int eMovie_getGeneroInt(char *generoString, int *generoInt)
{
	int todoOk = 0;

	char generoDrama[20] = "Drama";
	char generoComedia[20] = "Comedia";
	char generoAccion[20] = "Accion";
	char generoTerror[20] = "Terror";

	if (generoString != NULL && generoInt != NULL)
	{
		if (strcmp(generoString, generoDrama) == 0)
		{
			*generoInt = 1;
		}
		else
		{
			if (strcmp(generoString, generoComedia) == 0)
			{
				*generoInt = 2;
			}
			else
			{
				if (strcmp(generoString, generoAccion) == 0)
				{
					*generoInt = 3;
				}
				else
				{
					if (strcmp(generoString, generoTerror) == 0)
					{
						*generoInt = 4;
					}
					else
					{
						*generoInt = 0;
					}
				}
			}
		}

		todoOk = 1;
	}

	return todoOk;
}
int eMovie_setRating(eMovie *e, float rating)
{
	int todoOk = 0;

	if (e != NULL && rating >= 0 && rating <= 10)
	{
		e->rating = rating;
		todoOk = 1;
	}

	return todoOk;
}
int eMovie_getRating(eMovie *e, float *rating)
{
	int todoOk = 0;

	if (e != NULL && rating != NULL)
	{
		*rating = e->rating;
		todoOk = 1;
	}

	return todoOk;
}

int mostrarPelicula(eMovie *e)
{
	int todoOk = 0;

	if (e != NULL)
	{
		int id;
		char titulo[50];
		char generoString[20];
		float rating;

		if (eMovie_getId(e, &id) &&
				eMovie_getTitulo(e, titulo) &&
				eMovie_getGeneroString(e, generoString) &&
				eMovie_getRating(e, &rating))
		{
			printf("%4d%32s       %15s        %9.1f\n",
						 id, titulo, generoString, rating);
			todoOk = 1;
		}
	}
	return todoOk;
}

int peliculaCompararGeneroYRating(void *a, void *b)
{
	int retorno = 0;

	if (a != NULL && b != NULL)
	{
		eMovie *movA;
		eMovie *movB;

		movA = (eMovie *)a;
		movB = (eMovie *)b;

		if (movA->genero > movB->genero)
		{
			retorno = 1;
		}
		else if (movA->genero < movB->genero)
		{
			retorno = -1;
		}
		else
		{
			if (movA->rating > movB->rating)
			{
				retorno = 1;
			}
			else if (movA->rating < movB->rating)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

int filtrarDrama(void *a)
{
	int rta = 0;

	eMovie *pMov = NULL;

	if (a != NULL)
	{
		pMov = (eMovie *)a;

		if (pMov->genero == 1)
		{
			rta = 1;
		}
	}

	return rta;
}
int filtrarComedia(void *a)
{
	int rta = 0;

	eMovie *pMov = NULL;

	if (a != NULL)
	{
		pMov = (eMovie *)a;

		if (pMov->genero == 2)
		{
			rta = 1;
		}
	}

	return rta;
}
int filtrarAccion(void *a)
{
	int rta = 0;

	eMovie *pMov = NULL;

	if (a != NULL)
	{
		pMov = (eMovie *)a;

		if (pMov->genero == 3)
		{
			rta = 1;
		}
	}

	return rta;
}
int filtrarTerror(void *a)
{
	int rta = 0;

	eMovie *pMov = NULL;

	if (a != NULL)
	{
		pMov = (eMovie *)a;

		if (pMov->genero == 4)
		{
			rta = 1;
		}
	}

	return rta;
}

void *asignarGenero(void *a)
{
	eMovie *pMov = NULL;

	if (a != NULL)
	{
		pMov = (eMovie *)a;

		int min = 1;
		int max = 4;
		int generoAsignado;

		generoAsignado = (rand() % (max - min + 1)) + min;
		pMov->genero = generoAsignado;
	}

	return pMov;
}
void *asignarRating(void *a)
{
	eMovie *pMov = NULL;

	if (a != NULL)
	{
		pMov = (eMovie *)a;

		int min = 10;
		int max = 100;
		float ratingAsignado;

		ratingAsignado = (float)((rand() % (max - min + 1)) + min) / 10;
		pMov->rating = ratingAsignado;
	}

	return pMov;
}
