/*
 * General.h
 *
 *  Created on: 17 feb. 2022
 *      Author: brake
 */

#ifndef GENERAL_H_
#define GENERAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void menu(void);

int ingresarEnteroConMaximo(char mensaje[],int maximo);
void pedirString(char mensaje[], char stringIngresado[]);
void lowerToUpper(char array[]);
int validacionString(char array[]);
void MensajeDeError(int corroboracion, char mensaje[], char mensajeError[]);



#endif /* GENERAL_H_ */
