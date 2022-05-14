/*
 * biblioteca_UTN.c
 *
 *  Created on: 8 may. 2022
 *      Author: bongi
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "biblioteca_UTN.h"
int getIntFloat (float* pResultado)
{
    int retorno = -1;
    char buffer[4096];


    if (myGetsFloat(buffer, sizeof(buffer)) && esNumericoFlotante(buffer))
    {
        retorno = 0;
        *pResultado = atof(buffer);
    }
    return retorno;
}
int myGetsFloat(char* cadena, int longitud)
{
    char buffer[4096];
    fflush(stdin);
    scanf("%s", buffer);
    strncpy(cadena, buffer,longitud);
    return -1;
}
int validarEnteroFlotante(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    float buffer;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);

            if (getIntFloat(&buffer)== 0 && buffer >= minimo && buffer <= maximo)
            {
                *pResultado = buffer;
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s", mensajeError);
        }
        while (reintentos >= 0);
    }

    return retorno;
}


int esNumericoFlotante(char str[])
{
    int i = 0;
    int cantidadPuntos = 0;
    while (str[i] != '\0')
    {
        if (i == 0 && str[i] == '-')
        {
            i++;
            continue;
        }
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int utn_getNumeroEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int bufferInt;
	int retorno=-1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
	  do{
	     printf("%s",mensaje);
	     fflush(stdin);
	     scanf("%d",&bufferInt);


	     if(bufferInt >=minimo && bufferInt <=maximo && (isalpha(bufferInt)==0))
	     {
	    	*pResultado=bufferInt;
	    	retorno=0;
	    	break;
	     }
	     else
	     {
	    	 printf("%s:",mensajeError);
	    	 reintentos--;
	     }

	  }while(reintentos >0 );
	}
	return retorno;
}
int utn_getNombre(char pResultado[],char mensaje[],int tamanio)
{
  int retorno=-1;

     if(pResultado != NULL && mensaje != NULL && tamanio > 0)
     {
	            printf("%s",mensaje);
	            fflush(stdin);
	            fgets(pResultado,tamanio,stdin);

	            pResultado[strlen(pResultado)-1]='\0';
	            retorno=0;


	            for(int i=0;i<1;i++)
	            {
	                if((isalpha(pResultado[i])==0))
	            	{
	            	    printf("error,vuelva a ingresar: ");
	            	    fflush(stdin);
	            	    fgets(pResultado,tamanio,stdin);

	            	    pResultado[strlen(pResultado)-1]='\0';
	            	    retorno=0;

	             	}
	            }
	   }
  return retorno;
}
