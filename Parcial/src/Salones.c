/*
 * Salones.c
 *
 *  Created on: 16 oct 2021
 *      Author: Matii
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Salones.h"
#include "pedirDatos.h"

int inicializarSalones(Salones* lista, int tam){
	int retorno = ERROR;

	if(lista != NULL && tam >1){
		for(int i = 0; i < tam ; i++){
				lista[i].isEmpty = LIBRE;
			}
		retorno=EXITO;
	}
	return retorno;
}
void hardcodeoSalones(Salones* lista,int id, char nombre[],char direccion[],int tipo, int indice){
    lista[indice].id = id;
    strncpy(lista[indice].nombre,nombre,TAMANIO_STIRNG);
    strncpy(lista[indice].direccion,direccion,TAMANIO_STIRNG);
    lista[indice].tipo = tipo;
    lista[indice].isEmpty= OCUPADO;
}

/*
 * return 0 error en la carga
 * return 1 cargar exitosa
 * return -1 no hay lugar para cargar  *
 */
int crearSalon(Salones* lista, int tam,int* AIID){

	int retorno = ERROR;

	for(int i = 0; i < tam ; i++){

		if(lista[i].isEmpty ==0){

			lista[i].id= *AIID;

			if(pedirStringTexto(lista[i].nombre,TAMANIO_STIRNG, "Ingrese el nombre del salon: ", "\nEl nombre ingresado es incorrecto\n",REINTENTOS) == 0)break;

			if(pedirStringTexto(lista[i].direccion, TAMANIO_STIRNG, "Ingrese la direccion del salon: ", "\nLa direccion del salon es incorrecta\n",REINTENTOS)==0)break;

			if(pedirStringEntero(&lista[i].tipo, "Ingrese el tipo de salon(0:Shopping-1:Local): ", "\nEl valor ingresado es incorrecto o no es un numero.\n", 0, 1, REINTENTOS)==0)break;

			lista[i].isEmpty =1;

			retorno = EXITO;

		    break;
		}
		retorno = -1;

	}
	(*AIID)++;
	return retorno;
}

/*
 * return = 0 Los paramatros que pasaron no son compatibles
 * reutrn = i Encontro el ID que buscaba
 * 
 */

int buscarSalonesId(Salones* lista, int tam,int id){

	int retorno =ERROR;
	
	for(int i = 0; i < tam ; i++){

		if(lista[i].id == id && lista[i].isEmpty ==1){
			
			retorno = i;

			break;
		}
		retorno = 0;

	}
	return retorno;
}
/*
 * return = 0 No se pudo eliminar el empleado
 * reutrn = i Encontro el ID que buscaba
 * return = -1 nose encontro el ID
 */
int eliminarSalon(Salones* lista, int tam,int* borrarID){
    
    
	int retorno = ERROR;
	int auxBorrarId;
    imprimirSalones(lista,tam,1);
    
    pedirStringEntero(borrarID,"\nIngrese el ID del salon que desea eliminar: ", "\nNo es una opcion valida",1, INT_MAX, REINTENTOS);

	auxBorrarId = *borrarID;
	int index = buscarSalonesId(lista, tam,auxBorrarId);

	if(index != -1 && lista[index].isEmpty!=0){
		lista[index].isEmpty =0;
		retorno = EXITO;
	}



	return retorno;
}

int imprimirSalones(Salones* lista, int tam,int opcion){

	if (opcion ==0)
    {
		for(int i =0; i<tam ; i++){
			if(lista[i].isEmpty == OCUPADO){
				printf("\n%s %s %d",lista[i].nombre,lista[i].direccion,lista[i].tipo);
			}
		}
    }else if(opcion==1){
        for(int i =0; i<tam ; i++){
			if(lista[i].isEmpty == OCUPADO){
				printf("\n%d %s %s",lista[i].id,lista[i].nombre,lista[i].direccion);
			}
		}
    }
    
	
	return 1;
}
