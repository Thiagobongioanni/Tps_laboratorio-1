/*
 * arrayPassenger.h
 *
 *  Created on: 11 may. 2022
 *      Author: bongi
 */
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

int initPassenger(passenger list[],passenger aux,int tamanio);
int addPassengers(passenger list[],int tamanio,int *id);
int findPassengerById(passenger *list,int tamanio,int posicion);
int sortPassengers(passenger list[],passenger aux,int tamanio,int id);
int removePassenger(passenger list[],passenger aux,int posicion,char respuesta,int tamanio,int id);
int buscarLibre(passenger list[],int tamanio);
int menuModificacione(passenger list[],int posicion,char *respuesta);
int modificar(passenger list[],int posicion,passenger aux,int tamanio,char respuesta,int id);
int printPassengers(passenger list[],passenger aux,int tamanio,int id);
int sortPassengersByCode(passenger list[],passenger aux,int tamanio,int id);



#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_



#endif /* ARRAYPASSENGER_H_ */
