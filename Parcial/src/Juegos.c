/*
 * Juegos.c
 *
 *  Created on: 17 oct 2021
 *      Author: Matii
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Arcade.h"
#include "Juegos.h"




int inicializarJuegos(Juegos* lista, int tam){
	int retorno = ERROR;
	if(lista != NULL && tam >1){
		for(int i = 0; i < tam ; i++){
				lista[i].isEmpty = LIBRE;
			}
		retorno=EXITO;
	}
	return retorno;
}

int estado_nombre_juego(Juegos list[],int listLen, char nombre[]){
    int retorno=0;
    for(int i =0; i<listLen; i++){  
        if(list[i].isEmpty==1){
            if(strncmp(list[i].nombre,nombre,64)==0){
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

int generarListaJuegos(Arcades listaArcades[], int tamArcades,Juegos listaJuegos[], int tamJuegos ){

    if(inicializarJuegos(listaJuegos,tamJuegos)==EXITO){
      
    }
    int indexCli=0;
	int ultimoIndice;
    for (int i = 0; i < tamArcades; i++)
    {
        if(listaJuegos[i].isEmpty==0)
        {
            if(estado_nombre_juego(listaJuegos,tamJuegos, listaArcades[i].juego)==0){
                strncpy(listaJuegos[indexCli].nombre,listaArcades[i].juego,63);
                listaJuegos[indexCli].isEmpty=OCUPADO;
                indexCli++;
                
            }
        }
		ultimoIndice= i;
    }
    return ultimoIndice;
}

