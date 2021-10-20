/*
 * Arcade.c
 *
 *  Created on: 16 oct 2021
 *      Author: Matii
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Arcade.h"
#include "Salones.h"
#include "Informes.h"
#include "pedirDatos.h"


void hardcodeoArcades(Arcades* lista,int id, char nacionalidad[],int tipoSonido,int cantJugadores, int capacidadFichas,int idSalon, char juego[], int indice){
    lista[indice].id = id;
    strncpy(lista[indice].nacionalidad,nacionalidad,TAMANIO_STIRNG);
    lista[indice].tipoSonido = tipoSonido;
	lista[indice].cantJugadores = cantJugadores;
	lista[indice].capacidadFichas = capacidadFichas;
	lista[indice].idSalon = idSalon;
	strncpy(lista[indice].juego,juego,TAMANIO_STIRNG);
    lista[indice].isEmpty= OCUPADO;
}


int inicializarArcades(Arcades* lista, int tam){
	int retorno = ERROR;

	if(lista != NULL && tam >1){
		for(int i = 0; i < tam ; i++){
				lista[i].isEmpty = LIBRE;
			}
		retorno=EXITO;
	}
	return retorno;
}

int crearArcade(Arcades* lista, int tam, int* AIID,Salones* listaSalones){

	int retorno = ERROR;
	int bufferID;
	int encontroId=0;


	

	for(int i = 0; i < tam ; i++){

		if(lista[i].isEmpty ==0){

			lista[i].id = *AIID;

			if(pedirStringTexto(lista[i].nacionalidad,TAMANIO_STIRNG, "Ingrese la nacionalidad: ", "El nombre ingresado es incorrecto\n",REINTENTOS) == ERROR)break;

			if(pedirStringEntero(&lista[i].tipoSonido, "Ingrese el tipo de sonido(0:Estereo-1:Mono): ", "El valor ingresado es incorrecto o no es un numero.\n", ESTEREO, MONO, REINTENTOS)==ERROR)break;
			
            if(pedirStringEntero(&lista[i].cantJugadores, "Ingrese la cantidad de jugadores que permite (1-6): ", "El valor ingresado es incorrecto o no es un numero.\n", 1, 6, REINTENTOS)==ERROR)break;
            
            if(pedirStringEntero(&lista[i].capacidadFichas, "Ingrese la cantidad de fichas que almacena: ", "El valor ingresado es incorrecto o no es un numero.\n", 1, INT_MAX, REINTENTOS)==ERROR)break;

            if(pedirStringEntero(&lista[i].idSalon, "Ingrese el ID del salon al cuall pertenece: ", "El valor ingresado es incorrecto o no es un numero.\n", 0, INT_MAX, REINTENTOS)==ERROR)break;

			bufferID=lista[i].idSalon;

			encontroId = buscarSalonesId(listaSalones,tam,bufferID);
			
			if(encontroId==-1 || encontroId==0){
				printf("El ID ingresado no corresponde a un salon, cargue el arcade nuevamente");
				
				break;
			}


			if(pedirStringTexto(lista[i].juego, TAMANIO_STIRNG, "Ingrese el nombre del juego que posee: ", "El valos ingresado es incorrecto\n",REINTENTOS)==ERROR)break;


			lista[i].isEmpty =1;

			retorno = EXITO;

		    break;
		}
		retorno = -1;


	}
	(*AIID)++;
	return retorno;
}

int buscarPorId(Arcades* lista, int tam,int id){
	
	int retorno = ERROR;

	for(int i = 0; i < tam ; i++){
		
		if(lista[i].id == id && lista[i].isEmpty ==EXITO){

			retorno = i;

			break;
		}
		retorno = -1;

	}
	return retorno;
}

int modificarArcade(Arcades* lista, int tam){
	int modificarId;
	int retorno = ERROR;
	int cantJugadores;
	int juego;

	imprimirArcades(lista,tam);
	pedirStringEntero(&modificarId, "Ingrese el ID del arcade que desea modificar", "El valor ingresado es incorrecto o no es un numero.\n", 1, INT_MAX, REINTENTOS);


	int index = buscarPorId(lista, tam,modificarId);

	if(index != -1 && lista[index].isEmpty ==1 ){
		
		pedirStringEntero(&cantJugadores, "Dese modificar la cantidad de jugadores? 1(SI) 2(NO)", "El valor ingresado es incorrecto o no es un numero.", 1, 2, REINTENTOS);
		
		if (cantJugadores == 1)
		{
			pedirStringEntero(&lista[index].cantJugadores, "Ingrese la cantidad de jugadores que permite (1-6): ", "El valor ingresado es incorrecto o no es un numero.", 1, 6, REINTENTOS);
		}

		pedirStringEntero(&juego, "Dese modificar el Juego? 1(SI) 2(NO)", "El valor ingresado es incorrecto o no es un numero.", 1, 2, REINTENTOS);

		if (juego==1)

		{
			
			listarJuegos(lista,tam);
			
			pedirStringTexto(lista[index].juego, TAMANIO_STIRNG, "Ingrese el nombre del juego que posee: ", "El valos ingresado es incorrecto",REINTENTOS);
			
		}
		
		
		retorno = EXITO;
	}

	return retorno;
}

int eliminarArcade(Arcades* lista, int tam, int opcion){
    
	int borrarID;
	int retorno = ERROR;
	int confirmacion;
	if (opcion==0){

		imprimirArcades(lista,tam);
		
		pedirStringEntero(&borrarID,"Ingrese el ID del salon que desea eliminar", "No es una opcion valida",1, INT_MAX, REINTENTOS);

		int index = buscarPorId(lista, tam,borrarID);

		printf("\n%d %s %d %d %d %d %s",lista[index].id,lista[index].nacionalidad,lista[index].tipoSonido,lista[index].cantJugadores,lista[index].capacidadFichas,lista[index].idSalon,lista[index].juego);


		pedirStringEntero(&confirmacion,"Esta seguro que desea eliminar este Arcade. 1(SI) 2(NO)", "No es una opcion valida",1, 2, REINTENTOS);
		if(confirmacion==1){
			if(index != -1 && lista[index].isEmpty!=0){
				lista[index].isEmpty =0;
				retorno = EXITO;
			}
		}				
	}else{
		for(int i =0; i<tam ; i++){
			if(lista[i].idSalon == opcion){
				lista[i].isEmpty =0;
			}
		}
	}


		return retorno;
}

int imprimirArcades(Arcades* lista, int tam){


        for(int i =0; i<tam ; i++){
			if(lista[i].isEmpty == OCUPADO){
				printf("\n%d %s %d %d %d %d %s",lista[i].id,lista[i].nacionalidad,lista[i].tipoSonido,lista[i].cantJugadores,lista[i].capacidadFichas,lista[i].idSalon,lista[i].juego);
			}
		}
    
    
	
	return 1;
}

/*JUEGOS
*/
