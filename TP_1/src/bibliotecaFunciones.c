/*
 * calculo_resultados_validaciones.c
 *
 *  Created on: 13 abr. 2022
 *      Author: bongioanni thiago
 */
#include <stdio.h>
#include <stdlib.h>

float calculosDebito(float precioConDebito){
    float resultado;
    float descuento=0.10;

         descuento = precioConDebito  * descuento;
         resultado = precioConDebito - descuento;

    return resultado;
}

float calculosCredito(float precioConCredito){
	  float resultado;
	  float intereses=0.25;

	   intereses = precioConCredito * intereses;
	   resultado = precioConCredito + intereses;

	   return resultado;
}
float calculosBitcoin(float precioConBitcoin){
	  float unBitcoin=4676217.05;
	  float resultado;

      resultado=precioConBitcoin/unBitcoin;

	        return resultado;
}
float calculoUnitario (float kMS ,float precioUnitario)
{
	 float resultado;
           resultado = precioUnitario/kMS;

	 return resultado;
}
float calculoDiferenciaPrecios(float precioAero,float precioLatam){

	float resultado;

	       if(precioAero < precioLatam){
	    	  resultado=precioLatam-precioAero;
	       }else{
	    	  resultado=precioAero-precioLatam;
	       }

	 return resultado;
}
void cargaForzada()
{
	int kilometrosF = 7090;
    float precioAerolineasF=162965;
    float precioLatamF=159339;

	float calculoDAerolineasF;
	float calculoCAerolineasF;
	float calculosBAerolineasF;
	float calculoUAerolineasF;
	float calculoDifF;
	float calculoDLatamF;
	float calculosCLatamF;
	float calculosBLatamF;
	float calculoULatamF;

	                calculoDAerolineasF=calculosDebito(precioAerolineasF);
		    	    calculoCAerolineasF=calculosCredito(precioAerolineasF);
		    	    calculosBAerolineasF=calculosBitcoin(precioAerolineasF);
		    	    calculoUAerolineasF=calculoUnitario(kilometrosF,precioAerolineasF);

		    	    calculoDifF=calculoDiferenciaPrecios(precioAerolineasF,precioLatamF);

		    	    calculoDLatamF=calculosDebito(precioLatamF);
		    	    calculosCLatamF=calculosCredito(precioLatamF);
		    	    calculosBLatamF=calculosBitcoin(precioLatamF);
		    	    calculoULatamF=calculoUnitario(kilometrosF,precioLatamF);

		    	    printf("\nKMs ingresados: %d km\n",kilometrosF);

		    	    printf("\nprecio aerolineas:$ %.2f",precioAerolineasF);

		    	    printf("\nel precio de aerolineas con debito es: %.2f\n",calculoDAerolineasF);
		    	    printf("el precio de aerolineas con credito es: %.2f\n",calculoCAerolineasF);
		    	    printf("el precio de aerolineas con bitcoin es: %f\n",calculosBAerolineasF);
		    	    printf("\el precio unitario de aerolineas es: %.2f\n",calculoUAerolineasF);

		    	    printf("\nprecio  latam:$ %.2f",precioLatamF);

		    	    printf("\nel precio de Latam con debito es %.2f\n",calculoDLatamF);
		    	    printf("el precio de latam con credito es: %.2f\n",calculosCLatamF);
		    	    printf("el precio de latam con bitcoin es: %f\n",calculosBLatamF);
		    	    printf("\el precio unitario de latam es: %.2f\n",calculoULatamF);
		    	    printf("\nla diferencia de precio es %.2f\n",calculoDifF);
}

void mostrarResultados(int kilometros,float precioAerolineas,float precioLatam,float calculoDAerolineas,float calculoDLatam,float calculoCAerolineas,float calculosCLatam,float calculosBAerolineas,float calculosBLatam,float calculoUAerolineas,float calculoULatam,float calculoDif)
{
	 printf("\nKMs ingresados: %d km\n",kilometros);

     printf("\nPrecio aerolineas:$ %.2f",precioAerolineas);

     printf("\na) Precio con tarjeta de debito:$ %.2f\n",calculoDAerolineas);
	 printf("b) Precio con tarjeta de credito:$ %.2f\n",calculoCAerolineas);
     printf("c) Precio pagando con bitcoin: %f\n",calculosBAerolineas);
     printf("d) Precio unitario:$ %.2f\n",calculoUAerolineas);

	 printf("\nPrecio  latam:$ %.2f",precioLatam);

     printf("\na) Precio con tarjeta de debito es$ %.2f\n",calculoDLatam);
     printf("b) Precio con tarjeta de credito es:$ %.2f\n",calculosCLatam);
     printf("c) Precio pagando con bitcoin es: %f\n",calculosBLatam);
	 printf("d) Precio unitario:$ %.2f\n",calculoULatam);

     printf("\nLa diferencia de precio es:$ %.2f\n",calculoDif);

}

float funcionesDeCalculo(int kilometros,float precioAerolineas,float precioLatam,float*calculoDAerolineas,float*calculoCAerolineas,float*calculosBAerolineas,float*calculoUAerolineas,float*calculoDif,float*calculoDLatam,float*calculosCLatam,float*calculosBLatam,float*calculoULatam)
{
         int retorno=-1;

	             if(calculoDAerolineas != NULL && calculoCAerolineas != NULL &&  calculosBAerolineas != NULL && calculoUAerolineas != NULL && calculoDif != NULL && calculoDLatam != NULL && calculosCLatam != NULL && calculosBLatam != NULL && calculoULatam != NULL)
		           {
	                if(precioAerolineas >= 0 && precioLatam >= 0)
		            {
		               *calculoDAerolineas=calculosDebito(precioAerolineas);
		    	       *calculoCAerolineas=calculosCredito(precioAerolineas);
		    	       *calculosBAerolineas=calculosBitcoin(precioAerolineas);
		    	       *calculoUAerolineas=calculoUnitario(kilometros,precioAerolineas);

		    	       *calculoDif=calculoDiferenciaPrecios(precioAerolineas,precioLatam);

		    	       *calculoDLatam=calculosDebito(precioLatam);
		    	       *calculosCLatam=calculosCredito(precioLatam);
		    	       *calculosBLatam=calculosBitcoin(precioLatam);
		    	       *calculoULatam=calculoUnitario(kilometros,precioLatam);
		    	       retorno=0;
		            }
		           }

	return retorno;
}

int pedirDatos(int kilometros,float *precioAerolineas,float *precioLatam)
{
	int retorno=-1;
	      if(precioAerolineas != NULL && precioLatam != NULL )
	      {
	    	    printf("ingrese el precio de aereolineas: ");
	    	    scanf("%f", &*precioAerolineas);

	    	 	printf("ingrese el precio de latam: ");
	    	    scanf("%f", &*precioLatam);
	    	    retorno=0;
          }
	      if(*precioAerolineas < 0 || *precioAerolineas > 38000 || *precioLatam < 0 || *precioLatam > 38000)
	      {
	    	  printf("precios invalidos vuelva a ingresar los precios");
    	      printf("\ningrese el precio de aereolineas: ");
    	  	  scanf("%f", &*precioAerolineas);

    	  	  printf("ingrese el precio de latam: ");
    	  	  scanf("%f", &*precioLatam);
	    	  retorno=0;
	      }

	     return retorno;
}

#include <stdio.h>
#include <stdlib.h>

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
