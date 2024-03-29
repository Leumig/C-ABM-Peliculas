#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Menu.h"
#include "Controller.h"

int menu(LinkedList* pArrayListMovie)
{
	int todoOk = 0;
	int opcion;
	int cant = ll_len(pArrayListMovie);

	printf("  ***** MEN� DE OPCIONES *****     \n\n");
	printf("Ingrese una opci�n del 1 al 8: \n\n");

	printf("1. Cargar archivo. \n");
	printf("2. Imprimir lista. \n");
	printf("3. Asignar rating. \n");
	printf("4. Asignar g�nero. \n");
	printf("5. Filtrar por g�nero. \n");
	printf("6. Ordenar pel�culas. \n");
	printf("7. Guardar pel�culas. [Cantidad Actual: %d]\n\n", cant);

	printf("8. Salir. \n\n");

	printf("Ingrese opci�n: ");
	fflush(stdin);
	todoOk = scanf("%d", &opcion);

	if(todoOk)
	{
		return opcion;
	}

	return todoOk;
}

void confirmarSalidaMenu(char* p)
{
	if(p != NULL)
	{
		char confirma;

		printf("�Seguro que desea salir? (si = 's'  no = 'n') \n");
		fflush(stdin);
		scanf("%c", &confirma);
		confirma = tolower(confirma);

		while(confirma != 's' && confirma != 'n')
		{
			printf("Error, debe responder con 's' o 'n':  \n");
			fflush(stdin);
			scanf("%c", &confirma);
			confirma = tolower(confirma);
		}
		*p = confirma;
	}
}
