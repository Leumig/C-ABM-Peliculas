#ifndef MOVIE_H_
#define MOVIE_H_

typedef struct
{
	int id;
	char titulo[50];
	int genero;
	float rating;
} eMovie;

/// Constructores

/// @brief Reserva un espacio en memoria dinamica.
///
/// @return eMovie*
eMovie *eMovie_new();

/// @brief Recibe los parametros de un elemento de la estructura eMovie,
/// y le asigna un valor a cada campo mediante los setters.
///
/// @param id int
/// @param titulo char*
/// @param genero int
/// @param rating float
/// @return eMovie*
eMovie *eMovie_newParametros(int id, char *titulo, int genero, float rating);

/// Destructor

/// @brief Libera el espacio en memoria dinamica con la funcion free().
///
void eMovie_delete();

/// Setters y Getters

/// @brief Asigna el valor del ID.
///
/// @param e eMovie*
/// @param id int
/// @return devuelve 1 si funciona correctamente, de lo contrario 0
int eMovie_setId(eMovie *e, int id);

/// @brief Le carga un valor al segundo parametro recibido (ID).
///
/// @param e eMovie*
/// @param id int*
/// @return devuelve 1 si funciona correctamente, de lo contrario 0
int eMovie_getId(eMovie *e, int *id);

/// @brief Asigna el valor del Titulo.
///
/// @param e eMovie*
/// @param titulo char*
/// @return devuelve 1 si funciona correctamente, de lo contrario 0
int eMovie_setTitulo(eMovie *e, char *titulo);

/// @brief Le carga un valor al segundo parametro recibido (Titulo).
///
/// @param e eMovie*
/// @param titulo char*
/// @return devuelve 1 si funciona correctamente, de lo contrario 0
int eMovie_getTitulo(eMovie *e, char *titulo);

/// @brief Asigna el valor del Genero.
///
/// @param e eMovie*
/// @param genero int
/// @return devuelve 1 si funciona correctamente, de lo contrario 0
int eMovie_setGenero(eMovie *e, int genero);

/// @brief Le carga un valor al segundo parametro recibido (Genero).
///
/// @param e eMovie*
/// @param genero int*
/// @return devuelve 1 si funciona correctamente, de lo contrario 0
int eMovie_getGenero(eMovie *e, int *genero);

/// @brief Le carga un valor al segundo parametro recibido (Genero char).
///
/// @param e eMovie*
/// @param genero char*
/// @return devuelve 1 si funciona correctamente, y sino 0
int eMovie_getGeneroString(eMovie *e, char *genero);

/// @brief Le carga un valor al segundo parametro recibido (Genero int).
///
/// @param generoString char*
/// @param generoInt int*
/// @return devuelve 1 si funciona correctamente, de lo contrario 0
int eMovie_getGeneroInt(char *generoString, int *generoInt);

/// @brief Asigna el valor del Rating.
///
/// @param e eMovie*
/// @param rating float
/// @return devuelve 1 si funciona correctamente, de lo contrario 0
int eMovie_setRating(eMovie *e, float rating);

/// @brief Le carga un valor al segundo parametro recibido (Rating).
///
/// @param e eMovie*
/// @param rating float*
/// @return devuelve 1 si funciona correctamente, de lo contrario 0
int eMovie_getRating(eMovie *e, float *rating);

/// Mostrar

/// @brief Muestro los datos de una pelicula.
///
/// @param e eMovie*
/// @return retorna 1 al finalizar
int mostrarPelicula(eMovie *e);

/// Comparadores

/// @brief Compara los dos elementos recibidos para poder ordenarlos segun su Genero
/// y Rating gracias a la funci�n ll_sort.
///
/// @param a recibe al primer elemento
/// @param b recibe al segundo elemento
/// @return si el primer elemento es mayor al segundo devuelve 1, si es al reves
/// devuelve -1, y si son iguales o alguno es NULL devuelve 0
int peliculaCompararGeneroYRating(void *a, void *b);

/// Filters

/// @brief Analiza el campo genero del elemento recibido, y
/// responde a si es o no igual a 'Drama'.
///
/// @param a void*
/// @return devuelve 1 si la respuesta es si, de lo contrario 0
int filtrarDrama(void *a);

/// @brief Analiza el campo genero del elemento recibido, y
/// responde a si es o no igual a 'Comedia'.
///
/// @param a void*
/// @return devuelve 1 si la respuesta es si, de lo contrario 0
int filtrarComedia(void *a);

/// @brief Analiza el campo genero del elemento recibido, y
/// responde a si es o no igual a 'Accion'.
///
/// @param a void*
/// @return devuelve 1 si la respuesta es si, de lo contrario 0
int filtrarAccion(void *a);

/// @brief Analiza el campo genero del elemento recibido, y
/// responde a si es o no igual a 'Terror'.
///
/// @param a void*
/// @return devuelve 1 si la respuesta es si, de lo contrario 0
int filtrarTerror(void *a);

/// Mappers

/// @brief Asigna un valor de genero aleatoriamente.
///
/// @param a void*
void *asignarGenero(void *a);

/// @brief Asigna un valor de rating aleatoriamente.
///
/// @param a void*
void *asignarRating(void *a);

#endif /* MOVIE_H_ */
