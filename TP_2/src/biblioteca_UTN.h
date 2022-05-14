/*
 * biblioteca_UTN.h
 *
 *  Created on: 8 may. 2022
 *      Author: bongi
 */

/*recibimos una direcion de memoria un mensaje un mensaje de error un minimo un maximo y la catntidad de reintentos
 * esto va a ejecutarse mientras la cantidad de reintentos sea mayor a 0 o ingresen un dato valido
 * en caso de ingresar un dato valido se devuelve a la direccion de memoria que espera en la llamada mediante un puntero
 * se encarga de conseguir datos de tipo numerico enteros
 * retorna -1 si salio todo mal y muestra el mensaje de error ingresado y si sale todo bien devuelve 0
 */
int utn_getNumeroEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
/*recibimos una direcion de memoria un mensaje  y el tamanio del array
 * se encarga de conseguir datos de tipo char
 * en caso de ingresar un dato valido se devuelve a la direccion de memoria que espera en la llamada mediante un puntero
 * retorna -1 si salio todo mal y muestra el mensaje de error ingresado y si sale todo bien devuelve 0
 */
int utn_getNombre(char pResultado[],char mensaje[],int tamanio);
/*
 *
 */
int getIntFloat (float* pResultado);
int myGetsFloat(char* cadena, int longitud);
int validarEnteroFlotante(float* pResultado, char* mensaje,char* mensajeError, int minimo, int maximo, int reintentos);
int esNumericoFlotante(char str[]);

#ifndef BIBLIOTECA_UTN_H_
#define BIBLIOTECA_UTN_H_



#endif /* BIBLIOTECA_UTN_H_ */
