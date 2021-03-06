/*
 ============================================================================
 Name        : LAB17-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Articulos.h"
#include "controller.h"
#include "General.h"
int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	char auxiliar[50];
	int corroboracion;
	int flagMenu=-1;
	LinkedList* pArrayListArticulo=NULL;
	LinkedList* pArrayListListaConDescuento=NULL;

	pArrayListArticulo=ll_newLinkedList();
	pArrayListListaConDescuento=ll_newLinkedList();

	do
	{
		menu();
		opcion=ingresarEnteroConMaximo("ingrese opci?n", 6);
		switch(opcion)
		{
		case 1:
			pedirString("ingrese archivo que desea abrir: ", auxiliar);
			if(strcmp(auxiliar,"Datos_SP_LABO1.csv")==0)
			{
			corroboracion=controller_loadArticuloFromText("Datos_SP_LABO1.csv", pArrayListArticulo);
			MensajeDeError(corroboracion, "Carga completa\n", "error en la carga\n");
			}
			else
			{
				printf("error en la carga\n");
			}
			flagMenu=1;

			break;
		case 2:
			if(flagMenu==1)
			{
			corroboracion=controller_sortArticulo(pArrayListArticulo);
			MensajeDeError(corroboracion, "Carga completa.\n", "error en la carga.\n");
			}
			else
			{
				printf("Debe cargar articulos primero");
			}
			break;
		case 3:
			imprimirListaOrdenada(pArrayListArticulo);
			break;
		case 4:
			pArrayListListaConDescuento=ll_map(pArrayListArticulo,filtroDecuento);
			break;
		case 5:
			corroboracion=controller_saveArticulosAsTxt("mapeado.csv",pArrayListListaConDescuento);
		}

	}while(opcion!=6);






	return EXIT_SUCCESS;
}
