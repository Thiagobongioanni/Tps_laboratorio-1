/*
 ============================================================================
 Name        : TP_1.c
 Author      : Thiago Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaFunciones.h"

int main(void)
{
 setbuf(stdout,NULL);

 //variable utilizada para guardar la opcion elegida en el menu
 int opcion;
 //aqui se guardan los kilometros ingresados
 int kilometros=0;
 //aqui se guardan precios ingresados
 float precioAerolineas;
 float precioLatam;
 //aqui se guardan los calculos con tarejeta de Debito de cada aerolinea
 float calculoDAerolineas;
 float calculoDLatam;
 //aqui se guardan los calculos con tarejeta de credito de cada aerolinea
 float calculoCAerolineas;
 float calculosCLatam;
 //aqui se guarda el calculo del con Bitcoin
 float calculosBAerolineas;
 float calculosBLatam;
 //aqui se guarda el calculo unitario realizado
 float calculoUAerolineas;
 float calculoULatam;
 //aqui se guarda la diferencia de precio entre aerolineas
 float calculoDif;
 //validacion de datos
 int numeroValido;

	do
	{
	  system("CLS");
      printf("\n1)Ingresar kilometros %d""\n2)Ingresar precios de vuelos (aerolineas:%.2f) (latam:%.2f)" "\n3)Calcular todos los costos" "\n4)Informar resultados""\n5)Carga forzada de datos" "\n6)Salir\n",kilometros,precioAerolineas,precioLatam);

	  printf("\ningrese una opcion: ");
	  scanf("%d", &opcion);

	  switch(opcion)
	  {
	    system("pause");
	     case 1:

	    	 //esta funcion se encarga de validar los datos ingresados y se asegura que se ingresen en cierto rango
	    	 numeroValido = utn_getNumeroEntero(&kilometros,"ingrese los kilometros: ","cantidad invalida/n",0,20000,2);

	    	 if(numeroValido==-1) // si el numero recibido mediante el return de la funcion es -1 entonces algo salio mal y se muestra un aviso
	    	 {
	    		printf("numero invalido");
	    	 }
	     break;

	     case 2:
	    	 if (numeroValido==0)//si el numero es 0 entonces en la funcion salio todo bien y tinen permitido el ingreso de precios
	    	 {
	    		 //funcion en la que se solicitan los precios de los vuelos
	    	     pedirDatos(kilometros,&precioAerolineas,&precioLatam);
	    	 }
	     break;

	     case 3:
	    	    //en esta funcion se guardan todas las llamadas de las funciones dedicadas al calculo de los precios
	    	    funcionesDeCalculo(kilometros,precioAerolineas,precioLatam,&calculoDAerolineas,&calculoCAerolineas,&calculosBAerolineas,&calculoUAerolineas,&calculoDif,&calculoDLatam,&calculosCLatam,&calculosBLatam,&calculoULatam);
	     break;

	     case 4:
	    	 //esta funcion va a mostrar todos los resultados obtenidos en el case 3
	    	 mostrarResultados(kilometros,precioAerolineas,precioLatam,calculoDAerolineas,calculoDLatam,calculoCAerolineas,calculosCLatam,calculosBAerolineas,calculosBLatam,calculoUAerolineas,calculoULatam,calculoDif);
	    	 system("pause"); // este system("pause") nos permite ver detenidamente la consola y somos nosotros quienes decidimos cuando avanzar tocando alguna tecla
	     break;

	     case 5:
	    	 //esto es una funcion que contiene los precios y kilometros ya establecidos(realiza y muestra los calculos por su cuenta de manera instantanea)
	    	 cargaForzada();
	    	 system("pause");
	     break;

	     case 6:
	    	 //este case es el de salida al ingresarse el numero 6 en opciones se cierra la consola
	     break;

	     default:
	    	     printf("\nopcion no valida");//si el numero de la opcion elegida no corresponde a ningun case dara este aviso de error
	     break;
	  }
	}while(opcion!=6);//siempre que la opcion sea distinta de 6 seguira presentando el menu

	return 0;
}
