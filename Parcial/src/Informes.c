/*
 * Informes.c
 *
 *  Created on: 17 oct 2021
 *      Author: Matii
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Juegos.h"
#include "Arcade.h"
#include "Salones.h"
#include "pedirDatos.h"
#include "Informes.h"


void listarJuegos(Arcades listaArcades[], int tamArcades){   
  
    Juegos listaJuegos[CANTIDAD_ARCADES];

    generarListaJuegos(listaArcades, tamArcades, listaJuegos,tamArcades);
   
	for (int i = 0; i <tamArcades ; i++)
	{
        if (listaJuegos[i].isEmpty==OCUPADO)
        {
	    	printf("\n%s",listaJuegos[i].nombre);
    
        }
        
	}
	
    
    

}

int cantidadArcades(Salones listaSalones[],int tamSalones,Arcades listaArcades[],int tamArcades,int idSalon){
    
    int contadorArcades=0;

    for (int i = 0; i < tamArcades; i++)
    {
        if (listaArcades[i].isEmpty==OCUPADO)
        {
            if (listaArcades[i].idSalon==idSalon)
            {
               contadorArcades++;
            }
            
        }
        
    }
    return contadorArcades;
}

int cantidadFichas(Arcades listaArcades[],int tamArcades,int idSalon){
    int contadorFichas=0;

    for (int i = 0; i < tamArcades; i++)
    {
        if (listaArcades[i].isEmpty==OCUPADO)
        {
            if (listaArcades[i].idSalon == idSalon)
            {
               contadorFichas=contadorFichas + listaArcades[i].capacidadFichas;
            }
            
        }
        
    }
    return contadorFichas;
}
void cuatroArcades(Salones listaSalones[],int tamSalones,Arcades listaArcades[],int tamArcades){
    int arcades=0;

    for (int i = 0; i < tamSalones; i++)
    {
        if (listaSalones[i].isEmpty==1)
        {
            arcades = cantidadArcades(listaSalones,tamSalones,listaArcades,tamArcades,listaSalones[i].id);
            if (arcades>=4)
            {
                printf("\nID: %d Salon: %s Direccion: %s Tipo: %d",listaSalones[i].id,listaSalones[i].nombre,listaSalones[i].direccion,listaSalones[i].tipo);
                
            }
            
            arcades=0;
        }
        
    }
    

}

void multiplayer(Arcades listaArcades[],int tamArcades,Salones listaSalones[], int tamSalones){
    int indiceSalon;

    for (int i = 0; i < tamArcades; i++)
    {
        if (listaArcades[i].isEmpty==1)
        {
            if(listaArcades[i].cantJugadores>2){
                indiceSalon=buscarSalonesId(listaSalones,tamSalones,listaArcades[i].idSalon);

                printf("\nID: %d Cantidad de jugadores: %d Juego: %s Salon: %s",listaArcades[i].id,listaArcades[i].cantJugadores,listaArcades[i].juego,listaSalones[indiceSalon].nombre);

            }
        }
        
    }

}

void salonPorId(Salones listaSalones[],int tamSalones,Arcades listaArcades[],int tamArcades){
    
    int indiceSalon;
    int salonId;
    int contadorArcades=0;

    pedirStringEntero(&salonId, "\nIngrese el ID del salon que quiera imprimir: ", "\nEl valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS);

    indiceSalon=buscarSalonesId(listaSalones,tamSalones,salonId);
    if(indiceSalon!=-1 && indiceSalon!=0){
        contadorArcades = cantidadArcades(listaSalones,tamSalones,listaArcades,tamArcades,salonId);

        printf("\nNombre: %s Direccion: %s Tipo: %d Cantidad de Arcades: %d",listaSalones[indiceSalon].nombre,listaSalones[indiceSalon].direccion,listaSalones[indiceSalon].tipo, contadorArcades);
    }else{
        printf("No se encontro un salon con el ID ingresado");
    }

}

void arcadesDelSalon(Salones listaSalones[],int tamSalones,Arcades listaArcades[],int tamArcades){
    
    int indiceSalon;
    int salonId;

    pedirStringEntero(&salonId, "\nIngrese el ID del salon que quiera imprimir: ", "El valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS);

    indiceSalon=buscarSalonesId(listaSalones,tamSalones,salonId);

    if(indiceSalon!=-1 && indiceSalon!=0){
        printf("\n%s %d ",listaSalones[indiceSalon].nombre,listaSalones[indiceSalon].tipo);

        for (int i = 0; i < tamArcades; i++)
        {
            if (listaArcades[i].isEmpty==OCUPADO)
            {
                if (listaArcades[i].idSalon==listaSalones[indiceSalon].id)
                {
                printf("\nID: %d Nacionalidad: %s Tipo de sonido: %d Jugadores: %d Cantidad de fichas: %d Salon: %d Juego: %s",listaArcades[i].id,listaArcades[i].nacionalidad,listaArcades[i].tipoSonido,listaArcades[i].cantJugadores,listaArcades[i].capacidadFichas,listaArcades[i].idSalon,listaArcades[i].juego);
                
                }
            
            }
        }
    }else{
        printf("No se encontro un salon con el ID ingresado");
    }
}

void mayorCantidadArcades(Salones listaSalones[],int tamSalones,Arcades listaArcades[],int tamArcades){
    int arcades=0;
    int salonMasArcades=0;
    int masArcades=0;

    for (int i = 0; i < tamSalones; i++)
    {
        if (listaSalones[i].isEmpty==OCUPADO)
        {
            arcades= cantidadArcades(listaSalones,tamSalones,listaArcades,tamArcades,listaSalones[i].id);         

        }
        if (masArcades<arcades)
        {
            masArcades=arcades;
            salonMasArcades = i;
        }       
                
    }

    printf("\nID: %d Nombre: %s Direccion: %s",listaSalones[salonMasArcades].id,listaSalones[salonMasArcades].nombre,listaSalones[salonMasArcades].direccion);
   

}

void montoMaximo(Salones listaSalones[],int tamSalones,Arcades listaArcades[],int tamArcades){
    int salonId;
    int totalFichas;
    int precioPorFicha;
    int montoTotal;
    
    pedirStringEntero(&salonId, "Ingrese el ID del salon que quiera imprimir: ", "El valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS);
    pedirStringEntero(&precioPorFicha, "Ingrese el precio por ficha: ", "El valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS);
    totalFichas=cantidadFichas(listaArcades,tamArcades,salonId);
    montoTotal= totalFichas * precioPorFicha;

    printf("El monto total que puede recaudar el local es %d", montoTotal); 
}

void buscarPorJuego(Arcades listaArcades[],int tamArcades){
    char juego[63];
    int contadorJuegos=0;
    pedirStringTexto(juego,63, "Ingrese el nombre del juego: ", "El nombre ingresado es incorrecto",REINTENTOS);

    for (int i = 0; i < tamArcades; i++)
    {
        if (listaArcades[i].isEmpty==OCUPADO)
        {
            if(strncmp(listaArcades[i].juego,juego,63)==0){
                contadorJuegos++;
            }
            
        }
        
    }
    printf("El juego ingresado se encuentra en %d Arcades", contadorJuegos);

    
}

