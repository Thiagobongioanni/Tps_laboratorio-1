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


#define TAM 2
typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassanger;
    int statusFlight;
    int isEmpty;
}passenger;

int main(void)
{
	int opcion;
	int retornoF;
	int i;
	int id;
	passenger list[TAM];
	passenger aux;

	do
		{
		  //system("CLS");
	      printf("\n1)ALTAS ""\n2)MODIFICAR" "\n3)BAJA" "\n4)INFORMAR""\n5)Salir\n");
	      retornoF=utn_getNumeroEntero(&opcion,"ingrese una opcion: ","cantidad invalida/n",1,5,2);


		  switch(opcion)
		  {
		     case 1:
		    	    for(i=0;i<TAM;i++)
		    	    {
		    	    	id++;
		    	        list[i].id=id;
		    	 	    printf("\ningrese los datos del pasajero (numero de ID): %d\n",list[i].id);

		    	 	    printf("\ningrese el nombre: ");
		    	 	    fflush(stdin);
		    	 	    gets(list[i].name);
		    	 	    /*if (isalpha(list[i].name)==0){
		    	 	        printf("\n NO es un caracter alfabetico vuelva a ingresar los datos: ");
		    	 	        fflush(stdin);
		    	 	        gets(list[i].name);
		    	 	    }*/


		    	 	    printf("ingrese el apellido: ");
		    	 	    fflush(stdin);
		    	 	    gets(list[i].lastName);
		    	 	    /*if (isdigit(list[i].lastName)!=0){
		    	 	        printf("\n NO es un caracter alfabetico vuelva a ingresar los datos: ");
		    	 	        fflush(stdin);
		    	 	        gets(list[i].lastName);
		    	 	    }*/

		    	 	    printf("ingrese el precio: ");
		    	 	    scanf("%f",&list[i].price);
		    	 	    if (isalpha(list[i].price)==0){
		    	 	        printf("\n NO es un numero,vuelva a ingresar:");
		    	 	        fflush(stdin);
		    	 	        scanf("%f",&list[i].price);
		    	 	    }


		    	 	    printf("\ningrese el codigo del vuelo: ");
		    	 	    fflush(stdin);
		    	 	    gets(list[i].flyCode);

		    	 	    printf("ingrese el tipo de pasajero que es: ");
		    	 	    scanf("%d",&list[i].typePassanger);

		    	 	    printf("ingrese el status del vuelo: ");
		    	 	    scanf("%d",&list[i].statusFlight);

		    	 	    list[i].isEmpty=0;

		    	    }


		     break;

		     case 2:

		    	  printf("para modificar datos ingrese la ID del pasajero: ");
		    	  scanf("%d",&id);

		     break;

		     case 3:

		     break;

		     case 4:

		     break;

		     case 5:

		     break;

		     default:
		    	     printf("\nopcion no valida");
		     break;
		  }
		}while(opcion!=5);

		return 0;
}
