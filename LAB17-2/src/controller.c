/*
 * controller.c
 *
 *  Created on: 17 feb. 2022
 *      Author: brake
 */
#include "controller.h"
int controller_loadArticuloFromText(char* path, LinkedList* pArrayListArticulo)
{
	int idAux=-1;
	FILE* pFile;
	if (pArrayListArticulo!=NULL && path!=NULL)
	{
		pFile=fopen(path,"r");
		if(pFile!=NULL)
		{
			parser_articuloFromText(pFile, pArrayListArticulo);
			idAux=1;
		}
		fclose(pFile);
	}
	return idAux;

}

int controller_sortArticulo(LinkedList* pArrayListArticulo)
{
	int rtn=-1;
	printf("Ordenando segun articulo. Espere un momento...\n");
	rtn=ll_sort(pArrayListArticulo,articulo_sortByArticulo,1);
	return rtn;
}

void imprimirLista(LinkedList* pArrayListArticulo, int i)
{

	eArticulo* pArticuloAuxiliar;
	int id;
	char articulo[51];
	char medida[51];
	float precio;
	int rubroId;
	if(pArrayListArticulo!=NULL)
	{
		pArticuloAuxiliar=ll_get(pArrayListArticulo,i);
		articulo_getId(pArticuloAuxiliar, &id);
		articulo_getArticulo(pArticuloAuxiliar, articulo);
		articulo_getMedida(pArticuloAuxiliar, medida);
		articulo_getPrecio(pArticuloAuxiliar, &precio);
		articulo_getRubroId(pArticuloAuxiliar, &rubroId);

		printf("%d\t%35s\t%10s\t%.2f\t\t%d\n",id,articulo,medida,precio,rubroId);
	}

}

int imprimirListaOrdenada(LinkedList* pArrayListArticulo)
{
	int rtn=-1;
	if(pArrayListArticulo!=NULL && ll_len(pArrayListArticulo)>0)
	{
		printf("ID\t\t\t	Articulo\t   Medida\t Precio\t 	RubroId\n");
		for(int i=0;i<ll_len(pArrayListArticulo);i++)
		{
			imprimirLista(pArrayListArticulo,i);
			rtn=-1;
		}
	}
	return rtn;
}

int controller_saveArticulosAsTxt(char* path, LinkedList* pArrayListArticulo)
{
	int rtn=-1;
	FILE* pFile;
	if(path!=NULL && pArrayListArticulo!=NULL)
	{
		pFile=fopen(path,"w");
		if(pFile!=NULL)
		{
			rtn=saveArticuloAsText(pArrayListArticulo, pFile);
		}
		fclose(pFile);
	}
	return rtn;
}
