/*
 ============================================================================
 Name        : pruebaDeConsola.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculo_resultados_.h"


int utn_getNumeroEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int main(void)
{
	setbuf(stdout,NULL);

	//variable utilizada para las opciones del menu
	int opcion;
	//aqui se guardan los kilometros ingresados
	int kilometros=0;
	//precios ingresados
    float precioAerolineas;
	float precioLatam;
	//calculo con Debito
	float calculoDAerolineas;
	float calculoDLatam;
	//calculo con Credito
	float calculoCAerolineas;
	float calculosCLatam;
	//calculo con Bitcoin
	float calculosBAerolineas;
	float calculosBLatam;
	//calculo unitario
	float calculoUAerolineas;
	float calculoULatam;
	//diferencia de precio
	float calculoDif;
	//validacion
	int numeroValido;


	do
	{
	  system("CLS");
      printf("\n1)Ingresar kilometros %d"
    		  "\n2)Ingresar precios de vuelos (aerolineas:%.2f) (latam:%.2f)"
    		  "\n3)Calcular todos los costos"
    		  "\n4)Informar resultados"
    		  "\n5)Carga forzada de datos"
    		  "\n6)Salir\n",kilometros,precioAerolineas,precioLatam);
	  printf("\ningrese una opcion: ");
	  scanf("%d", &opcion);

	  switch(opcion)
	  {
	    system("pause");
	     case 1:
	    	 numeroValido = utn_getNumeroEntero(&kilometros,"ingrese los kilometros: ","cantidad invalida/n",0,20000,2);
	    	 if(numeroValido==0)
	    	 {
	    		printf("numero valido");
	    	 }
	     break;

	     case 2:
	    	 if (numeroValido==0)
	    	 {
	    	     pedirDatos(kilometros,&precioAerolineas,&precioLatam);
	    	 }
	     break;

	     case 3:
	    	 funcionesDeCalculo(kilometros,precioAerolineas,precioLatam,&calculoDAerolineas,&calculoCAerolineas,&calculosBAerolineas,&calculoUAerolineas,&calculoDif,&calculoDLatam,&calculosCLatam,&calculosBLatam,&calculoULatam);
	     break;

	     case 4:
	    	 mostrarResultados(kilometros,precioAerolineas,precioLatam,calculoDAerolineas,calculoDLatam,calculoCAerolineas,calculosCLatam,calculosBAerolineas,calculosBLatam,calculoUAerolineas,calculoULatam,calculoDif);
	    	 system("pause");
	     break;

	     case 5:
	    	 cargaForzada();
	    	 system("pause");
	     break;
	     case 6:
	    	 system("pause");
	     break;

	     default:
	    	     printf("\nopcion no valida");
	     break;
	  }
	}while(opcion!=6);
//
	return 0;
}
int utn_getNumeroEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int bufferInt;
	int retorno=-1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
	  do{
	     printf("%s",mensaje);
	     scanf("%d",&bufferInt);
	     if(bufferInt >=minimo && bufferInt <=maximo)
	     {
	    	*pResultado=bufferInt;
	    	retorno=0;
	    	break;
	     }
	     else
	     {
	    	 printf("%s",mensajeError);
	    	 reintentos--;
	     }
	  }while(reintentos >=0);
	}
	return retorno;
}
