/*
 * parser.c
 *
 *  Created on: 17 feb. 2022
 *      Author: brake
 */


#include "parser.h"
int parser_articuloFromText(FILE* pFile, LinkedList* pArrayListArticulo)
{
	int idAux;
	char id[100];
	char articulo[100];
	char medida[100];
	char precio[100];
	char rubroId[100];
	eArticulo* pArticulo;
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,articulo,medida,precio,rubroId);
	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,articulo,medida,precio,rubroId);
		pArticulo= articulos_newParametros(id, articulo, medida, precio, rubroId);
		ll_add(pArrayListArticulo,pArticulo);
		articulo_getId(pArticulo, &idAux);
	}
	return idAux;


}


int saveArticuloAsText(LinkedList* pArrayListArticulo, FILE* path)
{
	int rtn=-1;
	eArticulo* pArticulo;
	int id;
	char articulo[100];
	char medida[100];
	float precio;
	int rubroId;
	fprintf(path,"id,articulo,medida,precio,rubroId\n");
	for(int i=0;i<ll_len(pArrayListArticulo);i++)
	{
		pArticulo=ll_get(pArrayListArticulo,i);
		articulo_getId(pArticulo,&id);
		articulo_getArticulo(pArticulo, articulo);
		articulo_getMedida(pArticulo, medida);
		articulo_getPrecio(pArticulo, &precio);
		articulo_getRubroId(pArticulo, &rubroId);
		fprintf(path,"%d,%s,%s,%.2f,%d\n",id,articulo,medida,precio,rubroId);
		rtn=-1;
	}
	return rtn;
}
