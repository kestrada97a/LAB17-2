#include "General.h"
///brief: menu para el main
///param: void
///
void menu(void)
{
	printf("1- Abrir archivo De Articulos\n"
		   "2- Ordenar lista por Articulos\n"
		   "3- Imprimir lista de Articuols\n"
		   "4- Generar el archivo 'mapeado.csv'\n"
		   "5- Generar lista con descuento");
}



//brief pide un entero a ingresar pero limitado con un maximo incluido
//param char mensaje[]
//return int numeroIngresado
int ingresarEnteroConMaximo(char mensaje[],int maximo)
{
	int numeroIngresado;
	char term;
	printf("%s",mensaje);
	while((scanf("%d%c", &numeroIngresado, &term) != 2 || term != '\n')||(numeroIngresado<1 || numeroIngresado>maximo))
	{
		printf("Digito invalido. %s",mensaje);
		fflush(stdin);
	}
	return numeroIngresado;
}

//brief pide un string a ingresar
//param char mensaje[], char stringIngresado
//return void
void pedirString(char mensaje[], char stringIngresado[])
{
		int auxiliar;
		printf("%s \n",mensaje);
		fflush(stdin);
		scanf("%[^\n]",stringIngresado);
		//auxiliar=validacionString(stringIngresado);

		while(auxiliar==-1)
		{
			printf("Error. Reingrese solo letras: \n");
			fflush(stdin);
			scanf("%[^\n]",stringIngresado);
			//auxiliar=validacionString(stringIngresado);

		}

}

//brief transforma la primer letra de una oracion a UpperCase, usado junto a la funcion pedirString
//param char array[]
//return void
void lowerToUpper(char array[])
{
	char auxiliar[51];
	strcpy(auxiliar,array);
	strlwr(auxiliar);
	for(int i=0; i<strlen(auxiliar);i++)
	{
		auxiliar[0] = toupper(auxiliar[0]);
		break;
	}
	strcpy(array,auxiliar);
}

//brief valida que solo se escriban letras en un string, usado junto a la funcion pedirString
//param char array[]
//return int rtn
int validacionString(char array[])
{
	int rtn=0;
	for(int i=0;i<strlen(array);i++)
	{
		if(!(array[i]>=65 && array[i]<=90) && !(array[i]>=97 && array[i]<=122))
		{
			if(array[i]!=' ' || array[i-1]==' ')
			{
				rtn=-1;
				break;
			}
		}
	}
	return rtn;
}

//brief mensaje de error para corroborar que se hayan procesado bien las cosas
//param int datoACORROBORAR, char mensaje[], char mensajeError[]
//return void
void MensajeDeError(int corroboracion, char mensaje[], char mensajeError[])
{

	if(corroboracion>=0)
	{
		printf("%s",mensaje);
	}else {
		printf("%s",mensajeError);
	}

}
