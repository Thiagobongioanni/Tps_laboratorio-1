/*
 * arrayPassenger.c
 *
 *  Created on: 11 may. 2022
 *      Author: bongi
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "biblioteca_UTN.h"
#include "arrayPassenger.h"


int initPassenger(passenger list[],passenger aux,int tamanio)
{
	int retorno=-1;
	int i;

		    for(i=0;i<tamanio;i++)
			{
		    	strcpy(list[i].name,"");
		        strcpy(list[i].lastName,"");
		        list[i].price=0;
		        strcpy(list[i].flyCode," ");
		        list[i].typePassanger=0;
		        list[i].statusFlight=0;
		    	list[i].isEmpty=1;
			    retorno=0;
			}

		return retorno;
}

int addPassengers(passenger list[],int tamanio,int *id,int *contadorP)
{
	int retorno=-1;
	int espacio;

    passenger aux;

		 if(list != NULL && tamanio >0 && id != NULL )
		 {
			 retorno=0;
		    	espacio=buscarLibre(list,tamanio);
			    if(espacio == -1)
			    {
			       printf("el espacio  esta ocupado\n");
			    }
			    else
			    {
				    if((utn_getNombre(aux.name,"ingrese el nombre :",51)==0)&&
				      (utn_getNombre(aux.lastName,"ingrese el apellido :",51)==0)&&
					  (validarEnteroFlotante(&aux.price,"Ingrese el precio:","error ingrese un precio valido:",5000,100000,3)==0)&&
				      (utn_getNombre(aux.flyCode,"ingrese el codigo del vuelo:",51)==0)&&
					  (utn_getNumeroEntero(&aux.typePassanger,"\n1:joven, 2:adulto, 3:anciano\n ingrese el tipo de pasajero: ","cantidad invalida/n",1,3,2)==0)&&
					  (utn_getNumeroEntero(&aux.statusFlight,"\n1:activo, 2:cancelado \n ingrese el estado del vuelo: ","cantidad invalida/n",1,2,2)==0))
				    {
				    	    aux.id=0;

				    	    (*contadorP)++;
				    		(*id)++;
				    		aux.id=*id;
				    		aux.isEmpty=0;
				    		list[espacio]=aux;
				    }
				 }
		 }
		return retorno;
}
int findPassengerById(passenger *list,int tamanio,int posicion)
{
	int retorno=-1;
	int i;

		    for(i=0;i<tamanio;i++)
		    {
		    	if(list[i].id == posicion && list[i].isEmpty==0)
		    	{
		    		retorno=i;
		    	    break;
		    	}
		    }
   return retorno;
}
int sortPassengers(passenger list[],passenger aux,int tamanio,int id)
{
	int retorno=-1;
	int i;
	int j;

		 if(list != NULL && tamanio > 0)
		 {
			retorno=0;
		    for(i=0;i<tamanio-1;i++)
		    {
			    for(j=i+1;j<tamanio;j++)
			    {
				    if((strcmp(list[i].lastName,list[j].lastName))>0 && list[i].typePassanger > list[j].typePassanger)
				    {
				        aux=list[i];
				        list[i]=list[j];
				        list[j]=aux;
				    }
				}
			}

		    printf("\n tipos de pasajeros: "
		    		"\n1:joven, 2:adulto, 3:anciano\n");
		    printf("\n estado del vuelo:"
		    		"\n 1:activo, 2:cancelado\n");
			for(i=0;i<tamanio;i++)
			{
				if(list[i].isEmpty == 1)
				{
					continue;
				}
				else
				{
					id=list[i].id;
			        printf("\nel id es: %d %s  tipo:%d  %s precio: %.2f  flyCode:%s estado del vuelo: %d",id,list[i].lastName,list[i].typePassanger,list[i].name,list[i].price,list[i].flyCode,list[i].statusFlight);

				}
			}
		 }
		return retorno;
}
int removePassenger(passenger list[],passenger aux,int tamanio,int id)
{

		int retorno=-1;
		int retornoF;
		int i;
		int posicion;
		char respuesta;

	        if(list != NULL && tamanio > 0)
	        {
	           retorno=0;
		       printf("\n-----lista de empleados-----\n");
		       sortPassengers(list,aux,tamanio,id);
			   printf("\n----------------------------------\n");

		       printf("\ningrese la id que quiere dar de baja: \n");
		       scanf("%d",&posicion);

		       retornoF=findPassengerById(list,tamanio,posicion);
		       if(retornoF == -1)
		       {
		       	  printf("no encontramos el ID: %d",posicion);
		       }
		       else
		       {
		          printf("la id selecionada es del empleado: %s %s ¿desea darlo de baja?: ",list[posicion].name,list[posicion].lastName);
		          scanf("%s",&respuesta);
		          if(respuesta=='s')
		          {
		             for(i=0;i<tamanio;i++)
		             {
				         if(list[posicion].isEmpty==0)
				         {
				        	 list[posicion].isEmpty=1;
				         }
		             }
		          }
		       }
	        }

		return retorno;
}

int buscarLibre(passenger list[],int tamanio)
{
	int retorno=-1;
	int i;

	for(i=0;i<tamanio;i++)
	{
		if(list[i].isEmpty==1)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}
int menuModificacione(passenger list[],int posicion,char *respuesta)
{
 int opcionM;
 int retorno=-1;
 int valido;

  if(list != NULL && posicion >= 0 && respuesta != NULL)
  {
	retorno=0;
	do
	{
		printf("\n1)NOMBRE  \n2)APELLIDO \n3)PRECIO\n4)TIPO PASAJERO\n5)CODIGO DE VUELO");
		valido=utn_getNumeroEntero(&opcionM,"\ningrese una opcion: ","opcion invalida/n",1,5,2);
		if(valido==-1)
		{
			printf("numero invalido");
		}
		switch(opcionM)
		{
			   case 1:
				   if(valido==0)
				   {
			          printf("\ningrese el nuevo nombre: ");
			          fflush(stdin);
			          gets(list[posicion].name);
				   }
			   break;

			   case 2:
				   if(valido==0)
				   {
			          printf("\ningrese el nuevo apellido: ");
			          fflush(stdin);
			   	      gets(list[posicion].lastName);
				   }
			   break;

			   case 3:
				   if(valido==0)
				   {
			    	  printf("\ningrese el nuevo precio: ");
			    	  scanf("%f",&list[posicion].price);
				   }
			   break;

			   case 4:
				   if(valido==0)
				   {
					  printf("\n tipos de pasajeros:"
							  "\n 1:joven, 2:adulto, 3:anciano\n");
			          printf("\ningrese el nuevo tipo de pasajero: ");
			          scanf("%d",&list[posicion].typePassanger);
				   }
				   break;
			   case 5:
			        if(valido==0)
					{
			   		   printf("\ningrese el nuevo codigo de vuelo: ");
			   		   fflush(stdin);
			   		   gets(list[posicion].flyCode);
			   	    }
			        break;
			   }
			        printf("desea continuar?: ");
			        scanf("%s",&*respuesta);
	}while(*respuesta=='s');
  }

	return retorno;
}
int modificar(passenger list[],passenger aux,int tamanio,int id)
{
	{
		int retorno=-1;
		int retornoF;
		int posicion;
		char respuesta;


		     if(list != NULL && tamanio > 0)
		     {
		    	retorno=0;

		        printf("\n-----------------lista pasajeros---------------------------\n");
		        sortPassengers(list,aux,tamanio,id);
			    printf("\n------------------------------------------------------\n");

			    printf("ingese la id del pasajero que quiere modificar: ");
				scanf("%d",&posicion);


				retornoF=findPassengerById(list,tamanio,posicion);
				if(retornoF == -1)
				{
					printf("no encontramos el ID: %d",posicion);
				}
				else
			    {
				     printf("la id selecionada es: %d",list[posicion].id);

				    menuModificacione(list,posicion,&respuesta);

				}
		     }
		return retorno;
	}
}
int printPassengers(passenger list[],passenger aux,int tamanio,int id)
{
	int retorno=-1;
	int i;


			 if(list != NULL && tamanio > 0)
			 {
				retorno=0;
				for(i=0;i<tamanio;i++)
				{
					if(list[i].isEmpty == 1)
					{
						continue;
					}
					else
					{
					    id=list[i].id;

					    printf("\n tipos de pasajeros: "
					    		"\n1:joven, 2:adulto, 3:anciano\n");
					    printf("\n estado del vuelo:"
					    		"\n 1:activo, 2:cancelado\n");
					    printf("\n%d %s, %s, precio: %.2f, flyCode:%s, tipo: %d, estado del vuelo: %d",id,list[i].name,list[i].lastName,list[i].price,list[i].flyCode,list[i].typePassanger,list[i].statusFlight);

					}
				}
			 }
	return retorno;
}
int sortPassengersByCode(passenger list[],passenger aux,int tamanio,int id)
{
	int retorno=-1;
		int i;
		int j;

			 if(list != NULL && tamanio > 0)
			 {
				retorno=0;
			    for(i=0;i<tamanio-1;i++)
			    {
				    for(j=i+1;j<tamanio;j++)
				    {
					    if((strcmp(list[i].flyCode,list[j].flyCode))>0 && list[i].statusFlight > list[j].statusFlight)
					    {
					        aux=list[i];
					        list[i]=list[j];
					        list[j]=aux;
					    }
					}
				}
				for(i=0;i<tamanio;i++)
				{
					if(list[i].isEmpty == 1)
					{
						continue;
					}
					else
					{
						id=list[i].id;
						printf("\n tipos de pasajeros: "
								"\n1:joven, 2:adulto, 3:anciano\n");
						printf("\n estado del vuelo:"
								"\n 1:activo, 2:cancelado\n");
				        printf("\nid:%d  flyCode:%s estado del vuelo:%d %s, %s, precio: %.2f  tipo: %d",id,list[i].flyCode,list[i].statusFlight,list[i].name,list[i].lastName,list[i].price,list[i].typePassanger);
					}
				}
			 }
	return retorno;
}

int menuInformes(passenger list[],passenger aux,int id,int tamanio,int contadorP)
{
 int opcionM;
 int retorno=-1;
 int valido;
 char respuesta;
 float acumPrice=0;
 int promedioPrice=0;

  if(list != NULL && tamanio > 0)
  {
	retorno=0;
	do
	{
		printf("\n1)pasajeros por apellido y tipo de pasajero  \n2)pasajeros de forma encolumnada. \n3)pasajeros por codigo de vuelo y estado de vuelo\n4)promedio de los precios de los pasajes y cuantos pasajeros superan el precio promedio");
		valido=utn_getNumeroEntero(&opcionM,"\ningrese una opcion: ","opcion invalida/n",1,4,2);
		if(valido==-1)
		{
			printf("numero invalido");
		}
		switch(opcionM)
		{
			   case 1:
				   sortPassengers(list,aux,tamanio,id);
			   break;

			   case 2:
				   printPassengers(list,aux,tamanio,id);
			   break;

			   case 3:
				   sortPassengersByCode(list,aux,tamanio,id);
			   break;

			   case 4:
				   totalprecios(list,tamanio,acumPrice,contadorP,promedioPrice);
			   break;

		 }
		 printf("\ndesea continuar?: ");
	     scanf("%s",&respuesta);
	}while(respuesta=='s');
  }

	return retorno;
}
int totalprecios(passenger list[],int tamanio,float acumPrice,int contadorP,int promedioPrice)
{
	 int retorno=-1;
	 int i;
	 int contP=0;

	 if(list != NULL && tamanio > 0)
     {
		for(i=0;i<tamanio;i++)
		{
			acumPrice=acumPrice + list[i].price;
			promedioPrice=acumPrice/contadorP;

			if(list[i].price > promedioPrice)
			{
				contP++;
			}
		}
		for(i=0;i<1;i++)
		{
			printf("\nEl precio total es: %.2f",acumPrice);
		    printf("\nnEl promedio de los precios es: %d",promedioPrice);
		    printf("\nLa cantidad de pasajeros que superan el precio promedio es de: %d",contP);
		}

     }

	return retorno;
}
void cargaforzada()
{
	eForzada lista[5];
	int i;
			    for(i=0;i<5;i++)
				{
			    	lista[i].idF=i;
			    	strcpy(lista[0].nombreF,"juan");
			    	strcpy(lista[1].nombreF,"pedro");
			    	strcpy(lista[2].nombreF,"rodrigo");
			    	strcpy(lista[3].nombreF,"carlos");
			    	strcpy(lista[4].nombreF,"pepe");
			        strcpy(lista[0].apellidoF,"alvarez");
			        strcpy(lista[1].apellidoF,"garnacho");
			        strcpy(lista[2].apellidoF,"lopez");
			        strcpy(lista[3].apellidoF,"riquelme");
			        strcpy(lista[4].apellidoF,"gonzales");
			        lista[0].precioF=20000;
			        lista[1].precioF=3000;
			        lista[2].precioF=40000;
			        lista[3].precioF=23000;
			        lista[4].precioF=17000;
			        strcpy(lista[0].flyCodeF,"BIRtwo");
			        strcpy(lista[1].flyCodeF,"yfrc45");
			        strcpy(lista[2].flyCodeF,"uipm67");
			        strcpy(lista[3].flyCodeF,"ñkjg7");
			        strcpy(lista[4].flyCodeF,"iok0o");
			        lista[0].typePassangerF=1;
			        lista[1].typePassangerF=2;
			        lista[2].typePassangerF=3;
			        lista[3].typePassangerF=4;
			        lista[4].typePassangerF=1;
			        lista[0].statusF=0;
			    	lista[1].statusF=1;
			    	lista[2].statusF=0;
			    	lista[3].statusF=0;
			    	lista[4].statusF=1;
				}

                for(i=0;i<5;i++)
                {
                	printf("\n tipos de pasajeros: 1:"
                			"\njoven, 2:adulto, 3:anciano\n");
                	printf("\n estado del vuelo:"
                			"\n 1:activo, 2:cancelado\n");
                    printf("\nID:%d Nombre:%s Apellido:%s precio:$%.2f Flycode: %s Type Passanger:%d Status:%d ",lista[i].idF,lista[i].nombreF,lista[i].apellidoF,lista[i].precioF,lista[i].flyCodeF,lista[i].typePassangerF,lista[i].statusF=0);
                }
}

