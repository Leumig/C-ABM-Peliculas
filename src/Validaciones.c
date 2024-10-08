#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Validaciones.h"

int validarPath(char *path)
{
	int todoOk = 0;
	char limpiar[10] = "limpiar";

	for (int i = 0; i < strlen(path); i++)
	{
		while (path == NULL || (strlen(path)) < 1 || (strlen(path)) > 49 || path[i] == 42 ||
					 path[i] == 47 || path[i] == 63 || path[i] == 92 || path[i] == 58 || path[i] == 34 ||
					 path[i] == 60 || path[i] == 62 || path[i] == 124)
		{
			fflush(stdin);
			printf("\nNombre de archivo invalido. Debe ingresar entre 1-49 caracteres.\n");
			printf("No puede contener comillas dobles, barra invertida ni los siguientes caracteres / : * ? < > | \n");
			printf("[>] Reingrese: ");
			strcpy(path, limpiar);
			fflush(stdin);
			gets(path);
		}

		todoOk = 1;
	}

	return todoOk;
}

void validarOpcion(int *pOpcion)
{
	int opcion;
	opcion = *pOpcion;

	while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)
	{
		printf("\n[>] Error, debe ingresar una opcion del 1 al 4: ");
		fflush(stdin);
		scanf("%d", &opcion);
	}

	*pOpcion = opcion;
}
