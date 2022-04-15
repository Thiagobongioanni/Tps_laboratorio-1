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

int main(void)
{
	setbuf(stdout,NULL);

	//variable utilizada para las opciones del menu
	int opcion;
	//aqui se guardan los kilometros ingresados
	float kilometros=0;
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


	do
	{
      printf("\n1)Ingresar kilometros  "  "\n2)Ingresar precios de vuelos "	  "\n3)Calcular todos los costos"	  "\n4)Informar resultados"	  "\n5)Carga forzada de datos"	  "\n6)Salir\n");
	  printf("\ningrese una opcion: ");
	  scanf("%d", &opcion);

	  switch(opcion)
	  {
	     case 1:
	           printf("\n ingrese los kilometros: ");
	           scanf("%f", &kilometros);
	     break;

	     case 2:
	    	 pedirDatos(&kilometros,&precioAerolineas,&precioLatam);
	     break;

	     case 3:
	    	 funcionesDeCalculo(kilometros,precioAerolineas,precioLatam,&calculoDAerolineas,&calculoCAerolineas,&calculosBAerolineas,&calculoUAerolineas,&calculoDif,&calculoDLatam,&calculosCLatam,&calculosBLatam,&calculoULatam);
	     break;

	     case 4:
	    	 mostrarResultados(kilometros,precioAerolineas,precioLatam,calculoDAerolineas,calculoDLatam,calculoCAerolineas,calculosCLatam,calculosBAerolineas,calculosBLatam,calculoUAerolineas,calculoULatam,calculoDif);
	     break;

	     case 5:
	    	 cargaForzada();
	     break;
	     case 6:
	     break;
//
	     default:
	    	     printf("\nopcion no valida");
	     break;
	  }
	}while(opcion!=6);

	return 0;
}
