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
#include <stdlib.h>
#include <ctype.h>
#include "biblioteca_UTN.h"
#include "arrayPassenger.h"
#define TAM 2
int removePassenger(passenger list[],passenger aux,int posicion,char respuesta,int tamanio,int id);
int main(void)
{
	int opcion;
    int posicion=0;
	char respuesta='n';
	int retornoF;
	int id=0;
	passenger list[TAM];
	passenger aux;



	initPassenger(list,aux,TAM);

	do
		{
		  //system("CLS");
	      printf("\n1)ALTAS ""\n2)MODIFICAR" "\n3)BAJA" "\n4)INFORMAR""\n5)carga forzada\n6)salir");
	      retornoF=utn_getNumeroEntero(&opcion,"ingrese una opcion: ","cantidad invalida/n",1,5,2);


	      switch(opcion)
	      		  {
	      		     case 1:

	      		    	 if(retornoF==0)
	      		    	 {
	      		    		retornoF=addPassengers(list,TAM,&id);
	      		    	 }
	      		     break;

	      		     case 2:
                         if(retornoF==0)
                         {
	      		    	    modificar(list,posicion,aux,TAM,respuesta,id);
                         }
                         else
                         {
                        	 printf("no hay nada que modificar: ");
                         }

	      		     break;

	      		     case 3:
	      		    	 if(retornoF==0)
	      		         {
	      		    	   removePassenger(list,aux,posicion,respuesta,TAM,id);
	      		         }
	      		     break;

	      		     case 4:

	      		    	  sortPassengers(list,aux,TAM,id);
	      		    	  //precios total y promedio
	      		    	  //falta ordenar de manera encolumnada
	      		    	  //y por codigo de vuelo y eestado de vuelo

	      		     break;

	      		     case 5:
	      		    	 //carga forzada
	      		     break;

	      		     default:
	      		    	     printf("\nopcion no valida");
	      		     break;
	      		  }
	      		}while(opcion!=6);

	      	return 0;
}
