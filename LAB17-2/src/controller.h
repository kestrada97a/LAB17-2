/*
 * controller.h
 *
 *  Created on: 17 feb. 2022
 *      Author: brake
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "LinkedList.h"
#include "parser.h"
#include "Articulos.h"

int controller_loadArticuloFromText(char* path, LinkedList* pArrayListArticulo);
int controller_sortArticulo(LinkedList* pArrayListArticulo);

void imprimirLista(LinkedList* pArrayListArticulo, int i);
int imprimirListaOrdenada(LinkedList* pArrayListArticulo);
int controller_saveArticulosAsTxt(char* path, LinkedList* pArrayListArticulo);


#endif /* CONTROLLER_H_ */
