/*
 * Informes.h
 *
 *  Created on: 17 oct 2021
 *      Author: Matii
 */

#ifndef INFORMES_H_
#define INFORMES_H_


#include "Juegos.h"
#include "Arcade.h"

/**
 * @brief 
 * 
 * @param listaArcades 
 * @param tamArcades 
 */
void listarJuegos(Arcades listaArcades[], int tamArcades);
/**
 * @brief 
 * 
 * @param listaSalones 
 * @param tamSalones 
 * @param listaArcades 
 * @param tamArcades 
 */
void cuatroArcades(Salones listaSalones[],int tamSalones,Arcades listaArcades[],int tamArcades);
/**
 * @brief 
 * 
 * @param listaArcades 
 * @param tamArcades 
 * @param listaSalones 
 * @param tamSalones 
 */
void multiplayer(Arcades listaArcades[],int tamArcades,Salones listaSalones[], int tamSalones);
/**
 * @brief 
 * 
 * @param listaSalones 
 * @param tamSalones 
 * @param listaArcades 
 * @param tamArcades 
 */
void salonPorId(Salones listaSalones[],int tamSalones,Arcades listaArcades[],int tamArcades);
/**
 * @brief 
 * 
 * @param listaSalones 
 * @param tamSalones 
 * @param listaArcades 
 * @param tamArcades 
 */
void arcadesDelSalon(Salones listaSalones[],int tamSalones,Arcades listaArcades[],int tamArcades);
/**
 * @brief 
 * 
 * @param listaSalones 
 * @param tamSalones 
 * @param listaArcades 
 * @param tamArcades 
 */
void mayorCantidadArcades(Salones listaSalones[],int tamSalones,Arcades listaArcades[],int tamArcades);
/**
 * @brief 
 * 
 * @param listaSalones 
 * @param tamSalones 
 * @param listaArcades 
 * @param tamArcades 
 */
void montoMaximo(Salones listaSalones[],int tamSalones,Arcades listaArcades[],int tamArcades);
/**
 * @brief 
 * 
 * @param listaArcades 
 * @param tamArcades 
 */
void buscarPorJuego(Arcades listaArcades[],int tamArcades);



#endif /* INFORMES_H_ */
