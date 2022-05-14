/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "biblioteca_UTN.h"
#include "arrayPassenger.h"
#define TAM 2000

int main(void)
{
	setbuf(stdout,NULL);

	int opcion;
	int retornoF;
	int retornoA=-1;
	int id=0;
	int contadorP=0;


	passenger list[TAM];
	passenger aux;

	initPassenger(list,aux,TAM);

	do
		{
	      printf("\n1)ALTAS ""\n2)MODIFICAR" "\n3)BAJA" "\n4)INFORMAR""\n5)CARGA FORZADA\n6)SALIR");
	      retornoF=utn_getNumeroEntero(&opcion,"\ningrese una opcion: ","cantidad invalida/n",1,6,2);

	      switch(opcion)
	      		  {
	      		     case 1:

	      		    	 if(retornoF==0)
	      		    	 {
	      		    		retornoA=addPassengers(list,TAM,&id,&contadorP);
	      		    	 }
	      		     break;


	      		     case 2:
	      		    	if(retornoA==0)
	      		    	{
	      		    	    modificar(list,aux,TAM,id);
	      		    	}
	      		     break;

	      		     case 3:
	      		    	if(retornoA==0)
	      		    	{
	      		    	   removePassenger(list,aux,TAM,id);
	      		    	}
	      		     break;

	      		     case 4:
	      		    	   menuInformes(list,aux,id,TAM,contadorP);
	      		     break;

	      		     case 5:
	      		    	 cargaforzada();
	      		     break;
	      		  }
	      		}while(opcion!=6);

	      	return 0;
}
