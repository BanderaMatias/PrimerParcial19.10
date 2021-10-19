/*
 * Salones.h
 *
 *  Created on: 16 oct 2021
 *      Author: Matii
 */

#ifndef SALONES_H_
#define SALONES_H_

#define CANTIDAD_SALONES 100
#define OCUPADO 1
#define LIBRE 0
#define EXITO 1
#define ERROR 0
#define SHOPPING 1
#define LOCAL 2
#define REINTENTOS 3
#define TAMANIO_STIRNG 51

struct
{
 int id;
 char nombre[TAMANIO_STIRNG];
 char direccion[TAMANIO_STIRNG];
 int tipo;
 int isEmpty;
}typedef Salones;
/**
 * @brief Harcodea un elemento del array
 * 
 * @param lista Array de Salones 
 * @param id 
 * @param nombre 
 * @param direccion 
 * @param tipo 
 * @param indice 
 */
void hardcodeoSalones(Salones* lista,int id, char nombre[],char direccion[],int tipo, int indice);
/**
 * @brief Inicializa cada valos de isEmpty en 0
 * 
 * @param list  Array de Salones
 * @param tam Tamaño del array de salones 
 * @return int (0)ocurrio un error (1) Je ejjecuto correctamten la funcion
 */
int inicializarSalones(Salones* list, int tam);
/**
 * @brief Da de alta un salon
 * 
 * @param lista Array de Salones 
 * @param tam Tamaño del array de salones 
 * @param AIID Variable generada en el main que se auto incrementa cuando entra en al funcion, ID autoincrementable
 * @return int (0)ocurrio un error (1) Je ejjecuto correctamten la funcion
 */
int crearSalon(Salones* lista, int tam,int* AIID);
/**
 * @brief Elimina un salon
 * 
 * @param lista Array de Salones 
 * @param tam Tamaño del array de salones 
 * @param borrarID Almacena el ID ingresado por el usuario dentro d ela funcion para luego eliminar los arcades vinculados
 * @return int (0)ocurrio un error (1) Je ejjecuto correctamten la funcion
 */
int eliminarSalon(Salones* lista, int tam, int* borrarID);
/**
 * @brief Imprime todos los valores del array o uno solo dependiendo del vlaor de opcion
 * 
 * @param lista Array de Salones 
 * @param tam Tamaño del array de salones 
 * @param opcion Si(0) imprime toda la lista de (!=0) es el valor del indice que teine que imprimir 
 * @return int (0)ocurrio un error (1) Je ejjecuto correctamten la funcion
 */
int imprimirSalones(Salones* lista, int tam, int opcion);
/**
 * @brief Busca un elemento que tenga el mismo Id que le pasen
 * 
 * @param lista Array de Salones 
 * @param tam Tamaño del array de salones 
 * @param id Valor de ID que tiene que buscar
 * @return int int (0)Ocurrio un erro (-1)No se encontro el ID ingresado (i)posicion del Salon buscado
 */
int buscarSalonesId(Salones* lista, int tam,int id);


#endif /* SALONES_H_ */
