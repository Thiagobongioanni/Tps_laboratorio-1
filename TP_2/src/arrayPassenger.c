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
		    	list[i].isEmpty=1;
		    	aux.isEmpty=1;
			    retorno=0;
			}

		return retorno;
}

int addPassengers(passenger list[],int tamanio,int *id)
{
	int retorno=-1;
	int espacio;
	int i=0;
    passenger aux;

		 if(list != NULL && tamanio >0 && id != NULL )
		 {
		    	espacio=buscarLibre(list,tamanio);
			    if(espacio == -1)
			    {
			       printf("el espacio numero:%d esta ocupado\n",i);
			    }
			    else
			    {
				    if((utn_getNombre(aux.name,"ingrese el nombre :",51)==0)&&
				      (utn_getNombre(aux.lastName,"ingrese el apellido :",51)==0)&&
					  (validarEnteroFlotante(&aux.price,"Ingrese el precio:","error ingrese un flotante:",10000,100000,3)==0)&&
				      (utn_getNombre(aux.flyCode,"ingrese el codigo del vuelo:",51)==0)&&
					  (utn_getNumeroEntero(&aux.typePassanger,"ingrese el tipo de pasajero: ","cantidad invalida/n",1,3,2)==0)&&
					  (utn_getNumeroEntero(&aux.statusFlight,"ingrese el estado del vuelo: ","cantidad invalida/n",1,3,2)==0))
				    {
				    	    aux.id=0;

				    		(*id)++;
				    		aux.id=*id;
				    		aux.isEmpty=0;
				    		list[espacio]=aux;

				    		retorno=0;
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
			for(i=0;i<tamanio;i++)
			{
				if(list[i].isEmpty == 1)
				{
					continue;
				}
				else
				{
					id=list[i].id;
					printf("\nel id es: %d",id);
			        printf("\n %s, %s, precio: %.2f, flyCode:%s, tipo: %d, estado del vuelo: %d",list[i].name,list[i].lastName,list[i].price,list[i].flyCode,list[i].typePassanger,list[i].statusFlight);
			        //totalSalary(aEmpleados,tamanio,acumSalary);
			       // salaryPromedio(aEmpleados,tamanio,contadorE,acumSalary,promedio);
				}
			}
		 }
		return retorno;
}
int removePassenger(passenger list[],passenger aux,int posicion,char respuesta,int tamanio,int id)
{
	int retorno=-1;
	int retornoF;
    int i;
	        if(list != NULL && tamanio > 0 && posicion >= 0)
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
			          printf("\ningrese el nuevo tipo de pasajero: ");
			          scanf("%d",&list[posicion].typePassanger);
				   }
				   break;
			   case 5:
			        if(valido==0)
					{
			   		   printf("\ningrese el nuevo codigo de vuelo: ");
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
int modificar(passenger list[],int posicion,passenger aux,int tamanio,char respuesta,int id)
{
	{
		int retorno=-1;
		int retornoF;

		     if(list != NULL && posicion >= 0 && tamanio > 0)
		     {
		    	retorno=0;

		        printf("\n-----lista pasajeros----\n");
		        sortPassengers(list,aux,tamanio,id);
			    printf("\n-----------------------------------\n");

			    printf("ingese la id del pasajero que quiere modificar: ");
				scanf("%d",&posicion);


				retornoF=findPassengerById(list,tamanio,posicion);
				if(retornoF == -1)
				{
					printf("no encontramos el ID: %d",posicion);
				}
				else
			    {
				    printf("la id selecionada es del pasajero: %s %s ",list[posicion].name,list[posicion].lastName);
				    menuModificacione(list,posicion,&respuesta);
				}
		     }
		return retorno;
	}
}

