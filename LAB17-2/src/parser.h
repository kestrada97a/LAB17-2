/*
 * parser.h
 *
 *  Created on: 17 feb. 2022
 *      Author: brake
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "Articulos.h"
#include "LinkedList.h"

int parser_articuloFromText(FILE* pFile, LinkedList* pArrayListArticulo);
int saveArticuloAsText(LinkedList* pArrayListArticulo, FILE* path);




#endif /* PARSER_H_ */
