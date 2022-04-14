/*
 * calculo_resultados_validaciones.c
 *
 *  Created on: 13 abr. 2022
 *      Author: bongi
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
void cargaForzada(int kilometrosF,float precioAerolineasF,float precioLatamF)
{
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


