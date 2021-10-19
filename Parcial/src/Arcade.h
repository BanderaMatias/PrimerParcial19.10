/*
 * Arcade.h
 *
 *  Created on: 16 oct 2021
 *      Author: Matii
 */

#ifndef ARCADE_H_
#define ARCADE_H_
#include "Salones.h"


#define CANTIDAD_ARCADES 1000
#define ESTEREO 0
#define MONO 1

struct
{
 int id;
 char nacionalidad[51];
 int tipoSonido;
 int cantJugadores;
 int capacidadFichas;
 int idSalon;
 char juego[64];
 int isEmpty;
}typedef Arcades;

/**
 * @brief Funcion para harcodear datos dentro de la lista
 * 
 * @param lista Array del struc Acades
 * @param id Valor ID
 * @param nacionalidad String con la nacionalidad 
 * @param tipoSonido Valor del tipo de sonido, puede ser 0 o 1
 * @param cantJugadores 
 * @param capacidadFichas 
 * @param idSalon 
 * @param juego 
 * @param indice 
 */
void hardcodeoArcades(Arcades* lista,int id, char nacionalidad[],int tipoSonido,int cantJugadores, int capacidadFichas,int idSalon, char juego[], int indice);

/**
 * @brief Inicializa el valor del isEmpty en 0
 * 
 * @param lista Array de Arcades
 * @param tam Es el tamaño total del Array de Arcades
 * @return int 
 */
int inicializarArcades(Arcades* lista, int tam);

/**
 * @brief Da de alta un Arcade dentro del Array
 * 
 * @param lista Array de Arcades
 * @param tam Es el tamaño total del Array de Arcades
 * @param AIID ID auto incrementable
 * @param listaSalones Array de Salones 
 * @return int (0)ocurrio un error (1) Je ejjecuto correctamten la funcion
 */
int crearArcade(Arcades* lista, int tam, int* AIID, Salones* listaSalones);

/**
 * @brief Permite modificar los valores de un de un Arcade dentro del array
 * 
 * @param lista Array de Arcades
 * @param tam Es el tamaño total del Array de Arcades
 * @return int (0)ocurrio un error (1) Je ejjecuto correctamten la funcion
 */
int modificarArcade(Arcades* lista, int tam);

/**
 * @brief Baja logica, modifica el valor del isEmpty
 * 
 * @param lista Array de Arcades
 * @param tam Es el tamaño total del Array de Arcades
 * @param opcion Elige si es eliminacion por arcade o por baja de salon
 * @return int (0)ocurrio un error (1) Je ejjecuto correctamten la funcion
 */
int eliminarArcade(Arcades* lista, int tam,int opcion);

/**
 * @brief Imprime los valores del array cuando isEmpty = 1
 * 
 * @param lista Array de Arcades
 * @param tam Es el tamaño total del Array de Arcades
 * @return int (0)ocurrio un error (1) Je ejjecuto correctamten la funcion
 */
int imprimirArcades(Arcades* lista, int tam);

/**
 * @brief Permite identificar la posicion de un Salon en en array
 * 
 * @param lista Array de Arcades
 * @param tam Es el tamaño total del Array de Arcades
 * @param id Es el Id que debe buscar dentro del Array
 * @return int (0)Ocurrio un erro (-1)No se encontro el ID ingresado (i)posicion del Arcade buscado
 */
int buscarPorId(Arcades* lista, int tam,int id);

#endif /* ARCADE_H_ */
