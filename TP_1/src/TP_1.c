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
#include "calculo_resultados_validaciones.h"

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
	//calculo de diferencia
	float calculoDif;
	//carga forzada
	int kilometrosF = 7090;
	float precioAerolineasF=162965;
	float precioLatamF=159339;

	do
	{
      printf("\n1)Ingresar kilometros  \n2)Ingresar precios de vuelos \n3)Calcular todos los costos\n4)Informar resultados\n5)Carga forzada de datos\n6)Salir\n");
	  printf("\ningrese una opcion: ");
	  scanf("%d", &opcion);

	  switch(opcion)
	  {
	     case 1:
	           printf("\n ingrese los kilometros: ");
	           scanf("%d", &kilometros);
	           if(kilometros < 0 || kilometros == 0)
	           {
	        	     printf("\ncantidad invalida vuelva a ingresar los datos: ");
	        	     scanf("%d", &kilometros);
	           }

	     break;

	     case 2:
	        if(kilometros > 0 || kilometros < 510000000000 )
	    	{
	           printf("ingrese el precio de aereolineas: ");
	           scanf("%f", &precioAerolineas);

	           printf("ingrese el precio de latam: ");
	           scanf("%f", &precioLatam);

	    	}else if(precioAerolineas < 0)
	    	{
	    	   printf("\nporfavor ingrese un precio valido: ");
	    	   scanf("%f", &precioAerolineas);
	    	}
	    	else if(precioLatam < 0)
	    	{
	    		    printf("\nporfavor ingrese un precio valido: ");
	    		    scanf("%f", &precioLatam);
	    	}

	     break;

	     case 3:
	            if(precioAerolineas >= 0 && precioLatam >= 0)
	            {
	    	       calculoDAerolineas=calculosDebito(precioAerolineas);
	    	       calculoCAerolineas=calculosCredito(precioAerolineas);
	    	       calculosBAerolineas=calculosBitcoin(precioAerolineas);
	    	       calculoUAerolineas=calculoUnitario(kilometros,precioAerolineas);

	    	       calculoDif=calculoDiferenciaPrecios(precioAerolineas,precioLatam);

	    	       calculoDLatam=calculosDebito(precioLatam);
	    	       calculosCLatam=calculosCredito(precioLatam);
	    	       calculosBLatam=calculosBitcoin(precioLatam);
	    	       calculoULatam=calculoUnitario(kilometros,precioLatam);
	            }
	     break;

	     case 4:
	    	    printf("\nKMs ingresados: %d km\n",kilometros);

	    	    printf("\nprecio aerolineas:$ %.2f",precioAerolineas);

	    	    printf("\nel precio de aerolineas con debito es: %.2f\n",calculoDAerolineas);
	    	    printf("el precio de aerolineas con credito es: %.2f\n",calculoCAerolineas);
	    	    printf("el precio de aerolineas con bitcoin es: %f\n",calculosBAerolineas);
	    	    printf("\el precio unitario de aerolineas es: %.2f\n",calculoUAerolineas);

	    	    printf("\nprecio  latam:$ %.2f",precioLatam);

	    	    printf("\nel precio de Latam con debito es %.2f\n",calculoDLatam);
	    	    printf("el precio de latam con credito es: %.2f\n",calculosCLatam);
	    	    printf("el precio de latam con bitcoin es: %f\n",calculosBLatam);
	    	    printf("\el precio unitario de latam es: %.2f\n",calculoULatam);
	    	    printf("\nla diferencia de precio es %.2f\n",calculoDif);


	     break;

	     case 5:
	    	 cargaForzada(kilometrosF,precioAerolineasF,precioLatamF);
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
