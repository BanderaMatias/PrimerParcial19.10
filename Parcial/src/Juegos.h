/*
 * Juegos.h
 *
 *  Created on: 17 oct 2021
 *      Author: Matii
 */

#ifndef JUEGOS_H_
#define JUEGOS_H_
#include "Arcade.h"

struct
{
    char nombre[64];
    int isEmpty;
}typedef Juegos;
/**
 * @brief Inicializa los valores de la variable isEmpty en 0
 * 
 * @param lista Array de Juegos 
 * @param tam Tamaño de la lista arcades 
 * @return int 
 */
int inicializarJuegos(Juegos* lista, int tam);
/**
 * @brief 
 * 
 * @param list  Array de Juegos
 * @param listLen Tamaño de la lista arcades
 * @param nombre 
 * @return int (0)si el nombre no esta en la lista (1) si el nombre ya esta en la lista
 */
int estado_nombre_juego(Juegos list[],int listLen, char nombre[]);
/**
 * @brief agrega los nombres a la lista de juegos
 * 
 * @param listaArcades Array de Arcades
 * @param tamArcades Tamaño de la lista arcades
 * @param listaJuegos Array de Juegos
 * @param tamJuegos Tamaño de la lista Juegos
 * @return int 
 */
int generarListaJuegos(Arcades listaArcades[], int tamArcades,Juegos listaJuegos[], int tamJuegos );


#endif /* JUEGOS_H_ */
