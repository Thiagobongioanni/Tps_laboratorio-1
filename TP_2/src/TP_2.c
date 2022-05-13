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
#include <string.h>
#include "biblioteca_UTN.h"
#include "arrayPassenger.h"
#define TAM 2
int menuInformes(passenger list[],passenger aux,char *respuesta,int id,int tamanio);
int main(void)
{
	setbuf(stdout,NULL);

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
	      retornoF=utn_getNumeroEntero(&opcion,"\ningrese una opcion: ","cantidad invalida/n",1,5,2);


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
	      		    	 menuInformes(list,aux,&respuesta,id,TAM);
	      		    	  //precios total y promedio
	      		     break;

	      		     case 5:
	      		    	 //carga forzada
	      		     break;

	      		     case 6:
	      		     break;

	      		     default:
	      		    	     printf("\nopcion no valida");
	      		     break;
	      		  }
	      		}while(opcion!=6);

	      	return 0;
}
int menuInformes(passenger list[],passenger aux,char *respuesta,int id,int tamanio)
{
 int opcionM;
 int retorno=-1;
 int valido;

  if(list != NULL && respuesta != NULL)
  {
	retorno=0;
	do
	{
		printf("\n1)pasajeros por apellido y tipo de pasajero  \n2)pasajeros de forma encolumnada. \n3)pasajeros por código de vuelo y estado de vuelo\n4)promedio de los precios de los pasajes y cuántos pasajeros superan el precio promedio");
		valido=utn_getNumeroEntero(&opcionM,"\ningrese una opcion: ","opcion invalida/n",1,4,2);
		if(valido==-1)
		{
			printf("numero invalido");
		}
		switch(opcionM)
		{
			   case 1:
				   sortPassengers(list,aux,tamanio,id);
			   break;

			   case 2:
				   printPassengers(list,aux,tamanio,id);
			   break;

			   case 3:
				   sortPassengersByCode(list,aux,TAM,id);
			   break;

			   case 4:
			   break;

		 }
		 printf("desea continuar?: ");
	     scanf("%s",&*respuesta);
	}while(*respuesta=='s');
  }

	return retorno;
}
