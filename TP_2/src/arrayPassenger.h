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

typedef struct
{
   int idF;
   char nombreF[100];
   char apellidoF[100];
   float precioF;
   char flyCodeF[30];
   int typePassangerF;
   int statusF;
}eForzada;

/*por parametro le pasamos la variable list de tipo passanger que contiene la estructura y sus campos otra variable de tipo passenger y el tamanio.
 * inicializa los campos de la estructura para que no contengan basura
 * retorna un entero aunque no me parece necesario
 */
int initPassenger(passenger list[],passenger aux,int tamanio);
/*por parametro le pasamos la variable list de tipo passanger que contiene la estructura y sus campos un id de tipo puntero que se encarga
 * de contar la id que le corresponde a cada pasajero dado de alta y un contador que cuenta cuanta gente se dio de alta.
 * Agrega en un array de pasajeros existente los valores recibidos como parámetro en la primer
posición libre.
 * devuelve un 0 en caso de que haya salido todo bien y un -1 en caso de que no
 */
int addPassengers(passenger list[],int tamanio,int *id,int *contadorP);

/*por parametro le pasamos la variable list de tipo passanger que contiene la estructura y sus campos y le pasamos posicion que contiene el valor ingresado por el usuario
 * Busca un pasajero recibiendo como parámetro de búsqueda su Id.
 * en caso de que no exista el id ingresado se retorna -1 y en caso de encontrarlo se retorna la posicion del ID .
 */
int findPassengerById(passenger *list,int tamanio,int posicion);
/*por parametro le pasamos la variable list de tipo passanger que contiene la estructura y sus campos otra variable de tipo passenger,el tamanio y la id
 * Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o
 *descendente.
 *retorna -1 si salio todo mal y 0 si todo bien
 */
int sortPassengers(passenger list[],passenger aux,int tamanio,int id);
/*por parametro le pasamos la variable list y aux de tipo passanger que contiene la estructura y sus campos,la posicion a borrar la respuesta en caso de que quiera seguir borrando y el tamanio
 * Elimina de manera lógica (isEmpty Flag en 1) un pasajero recibiendo como parámetro su Id.
 */
int removePassenger(passenger list[],passenger aux,int tamanio,int id);
/*solamente recibe la variable list de tipo passanger y el tamanio
 * se encarga de buscar espacios libres y que puedan ser dados de alta
 * retorna -1 si todo mal y en caso de que todo sea correcto devuelve la posicion libre
 */
int buscarLibre(passenger list[],int tamanio);
/*
 * es un menu que contiene todas las opciones de modificacion
 */
int menuModificacione(passenger list[],int posicion,char *respuesta);
/*por parametro le pasamos la variable list de tipo passanger que contiene la estructura y sus campos otra variable de tipo passenger,el tamanio y la id del pasajero
 * modificamos los datos de un pasajero utilizando su id para selecionarlo y contiene el menu anterior
 * retorna -1 si todo mal y 0 si todo bien
 */
int modificar(passenger list[],passenger aux,int tamanio,int id);
/*
 * es un menu que te ofrece todos los tipos de listados y informes disponibles
 */
int menuInformes(passenger list[],passenger aux,int id,int tamanio,int contadorP);
/*por parametro le pasamos la variable list de tipo passanger que contiene la estructura y sus campos otra variable de tipo passenger,el tamanio y la id
 * Imprime el array de pasajeros de forma encolumnada.
 *retorna -1 si todo mal y 0 si todo bien
 */
int printPassengers(passenger list[],passenger aux,int tamanio,int id);
/*por parametro le pasamos la variable list de tipo passanger que contiene la estructura y sus campos otra variable de tipo passenger,el tamanio y la id
 * Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera descendente
 * retorna -1 si todo mal y 0 si todo bien
 */
int sortPassengersByCode(passenger list[],passenger aux,int tamanio,int id);
/*por parametro le pasamos la variable list de tipo passanger que contiene la estructura.
 * el tamanio y la id  un acumulador con todos los precios y un contador
 * Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
 * promedio.
 * retorna -1 si todo mal y 0 si todo bien
 */
int totalprecios(passenger list[],int tamanio,float acumprice,int contadorP,int promedioPrice);
/*
 * tiene 5 pasajeros cargados de forma manual osea forzada
 */
void cargaforzada();

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_



#endif /* ARRAYPASSENGER_H_ */
