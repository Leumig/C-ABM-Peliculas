#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Movie.h"
#include "Parser.h"
#include "Controller.h"

int parser_MovieFromText(FILE *pFile, LinkedList *pArrayListMovie)
{
	if (pFile != NULL && pArrayListMovie != NULL)
	{
		int cant = 0;
		char bufferLecturaFantasma[4][40];
		int contadorNuevos = 0;

		int id = 0;
		char titulo[50];
		int genero = 0;
		char generoString[50];
		float rating = 0;

		eMovie *auxMov = NULL;

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",
					 bufferLecturaFantasma[0], bufferLecturaFantasma[1], bufferLecturaFantasma[2], bufferLecturaFantasma[3]);

		while (!feof(pFile))
		{
			cant = fscanf(pFile, "%d,%[^,],%[^,],%f\n", &id, titulo, generoString, &rating);

			if (cant == 4)
			{
				eMovie_getGeneroInt(generoString, &genero);

				auxMov = eMovie_newParametros(id, titulo, genero, rating);

				if (auxMov != NULL)
				{
					ll_add(pArrayListMovie, auxMov);

					contadorNuevos++;
				}
			}
		}

		eMovie_delete(auxMov);

		printf("\n[Peliculas cargadas: %d]\n", contadorNuevos);
	}

	return 1;
}
