/*
 * calculo_resultados_validaciones.h
 *
 *  Created on: 13 abr. 2022
 *      Author: bongi
 */

/*realiza el calculo correspondiente a la forma de pago y se lo aplica a los precios
 * en este caso se decuenta un 10% al precio original
 * recibe un parametro de tipo float y devuelve un numero de tipo float
 *el return devuelve el precio ya modificado
 */
float calculosDebito(float precioConDebito);


/*realiza el calculo correspondiente a la forma de pago y se lo aplica a los precios
 * en este caso se le agrega un 25% al precio original
 *recibe un parametro de tipo float y devuelve un numero de tipo float
 *el return devuelve el precio ya modificado
 */
float calculosCredito(float precioConCredito);


/*@brief: realiza un calculo que nos permite saber cuanto seria en bitcoin el precio que nos ingresen .
 *@param:  recibe un parametro de tipo float y devuelve un numero de tipo float.
 *@return: el return devuelve el precio convertido
 */
float calculosBitcoin(float precioConBitcoin);


/*@brief: calcula el precio por cada kilometro(nos dice cuanto nos cuesta cada kilometro basandose en el precio ingresado)
 *@param:  recibe dos parametro de tipo float y devuelve un numero de tipo float
 *@return: el return devuelve el precio de cada kilometro
 */
float calculoUnitario (float kMS ,float precioUnitario);


/*@brief: realiza un calculo que nos permite saber la diferencia de precio entre ambas agencias
 *@param:  recibe dos parametro de tipo float y devuelve un numero de tipo float
 *@return: el return devuelve la diferencia de precio
 */
float calculoDiferenciaPrecios(float precioAero,float precioLatam);


/*@brief: realiza un calculo con los datos ya definidos (es una carga forzada )
 *@param:  no recibe parametros y no devuelve nada
 *@return: no contiene return es de tipo void
 */
void cargaForzada();


/**se encarga de mostrar por pantalla todos los resultados obtenidos
 * recibe 12 parametros(11 tipo float y 1 tipo int)
 * no contiene return es de tipo void
 */
void mostrarResultados(int kilometros,float precioAerolineas,float precioLatam,float calculoDAerolineas,float calculoDLatam,float calculoCAerolineas,float calculosCLatam,float calculosBAerolineas,float calculosBLatam,float calculoUAerolineas,float calculoULatam,float calculoDif);


/**esta funcion contiene todas las llamadas de funciones de tipo calculo
 * recibe 12 parametros(11 tipo float y 1 tipo int)
 * el return devuelve 0 si sale todo bien
 */
float funcionesDeCalculo(int kilometros,float precioAerolineas,float precioLatam,float*calculoDAerolineas,float*calculoCAerolineas,float*calculosBAerolineas,float*calculoUAerolineas,float*calculoDif,float*calculoDLatam,float*calculosCLatam,float*calculosBLatam,float*calculoULatam);


/**esta funcion pide los precios de las aerolineas y los guarda en las variables de tipo float y puntero
 * recibe 3 parametros de tipo float y no devuelve nada ya que es de tipo void
 */
int pedirDatos(int kilometros,float *precioAerolineas,float *precioLatam);


#ifndef CALCULO_RESULTADOS_VALIDACIONES_H_
#define CALCULO_RESULTADOS_VALIDACIONES_H_



#endif /* CALCULO_RESULTADOS_VALIDACIONES_H_ */
