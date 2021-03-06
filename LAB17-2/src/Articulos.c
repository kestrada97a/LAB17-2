#include "LinkedList.h"
#include "Articulos.h"
eArticulo* articulos_new()
{
	eArticulo* pArticulo;
	pArticulo=(eArticulo*)malloc(sizeof(eArticulo));

	return pArticulo;
}

eArticulo* articulos_newParametros(char* id, char* articulo, char* medida, char* precio, char* rubroId)
{
	eArticulo* pArticulo;
	pArticulo=articulos_new();

	if(pArticulo!=NULL && id!=NULL && articulo!=NULL && medida!=NULL && precio!=NULL && rubroId!=NULL)
		{
			articulo_setId(pArticulo, atoi(id));
			articulo_setArticulo(pArticulo, articulo);
			articulo_setMedida(pArticulo, medida);
			articulo_setPrecio(pArticulo, atof(precio));
			articulo_setRubroId(pArticulo, atoi(rubroId));

		}

		return pArticulo;
}

void articulo_delete(eArticulo* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}

}

int articulo_setId(eArticulo* this, int id)
{
	int rtn=-1;
	if(this!=NULL)
	{
		this->id=id;
		rtn=-1;
	}
	return rtn;
}

int articulo_getId(eArticulo* this, int* id)
{
	int rtn=-1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		rtn=1;
	}
	return rtn;
}
int articulo_setArticulo(eArticulo* this, char* articulo)
{
	int rtn=-1;
	if(this!=NULL && articulo!=NULL)
	{
		strcpy(this->articulo,articulo);
		rtn=1;
	}
		return rtn;
}
int articulo_getArticulo(eArticulo* this, char* articulo)
{
	int rtn=-1;
	if(this!=NULL && articulo!=NULL)
	{
		strcpy(articulo,this->articulo);
		rtn=1;
	}
		return rtn;
}

int articulo_setMedida(eArticulo* this, char* medida)
{
	int rtn=-1;
	if(this!=NULL && medida!=NULL)
	{
		strcpy(this->medida,medida);
		rtn=1;
	}
	return rtn;
}

int articulo_getMedida(eArticulo* this, char* medida)
{
	int rtn=-1;
	if(this!=NULL && medida!=NULL)
	{
		strcpy(medida,this->medida);
		rtn=1;
	}
	return rtn;
}
int articulo_setPrecio(eArticulo* this, float precio)
{
	int rtn=-1;
	if(this!=NULL)
	{
		this->precio=precio;
		rtn=1;
	}
	return rtn;
}

int articulo_getPrecio(eArticulo* this, float* precio)
{
	int rtn=-1;
	if(this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		rtn=1;
	}
	return rtn;
}


int articulo_setRubroId(eArticulo* this, int rubroId)
{
	int rtn=-1;
		if(this!=NULL)
		{
			this->rubroId=rubroId;
			rtn=1;
		}
		return rtn;
}


int articulo_getRubroId(eArticulo* this, int* rubroId)
{
	int rtn=-1;
	if(this!=NULL && rubroId!=NULL)
	{
		*rubroId=this->rubroId;
		rtn=1;
	}
	return rtn;
}

int articulo_sortByArticulo(void* primerDato, void* segundoDato)
{
	eArticulo* articuloUno;
	eArticulo* articuloDos;
	int rtn=-1;
	articuloUno=(eArticulo*)primerDato;
	articuloDos=(eArticulo*)segundoDato;
	if(articuloUno!=NULL && articuloDos!=NULL)
	{
		rtn=strcmp(articuloUno->articulo,articuloDos->articulo);
	}
	return rtn;
}


void* filtroDecuento(void* pElement)
{
	int auxiliar;
	eArticulo* pArticulo;
	pArticulo=pElement;
	if(pArticulo!=NULL)
	{
		if(pArticulo->precio>=120 && pArticulo->rubroId==1)
		{
			auxiliar=pArticulo->precio*20/100;
			pArticulo->precio=pArticulo->precio-auxiliar;
		}
		if(pArticulo->precio<=200 && pArticulo->rubroId==2)
		{
			auxiliar=pArticulo->precio*10/100;
			pArticulo->precio=pArticulo->precio-auxiliar;
		}
	}
	return pArticulo;

}
