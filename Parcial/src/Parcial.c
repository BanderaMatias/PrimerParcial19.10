/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Salones.h"
#include "Arcade.h"
#include "Juegos.h"
#include "Informes.h"
#include "pedirDatos.h"






int main(void) {
	setbuf(stdout,NULL);
	int AIIDSalones =1;
	int AIIDArcades =1;
	int menu;
	int submenu;
	int salir;
	int borrarID;
	int flagSalones=0;
	int flagArcades=0;

	int resultados;


	Salones listaSalones[CANTIDAD_SALONES];
	Arcades listaArcades[CANTIDAD_ARCADES];
	
	

	salir = 0;

	if(inicializarSalones(listaSalones, CANTIDAD_SALONES)==0){
		printf("Hubo un error al inicializar el array");
		salir=1;
	}
	hardcodeoSalones(listaSalones,100,"Salon1","Dirreccion1",1,0);
	hardcodeoSalones(listaSalones,200,"Salon2","Dirreccion2",1,1);
	hardcodeoSalones(listaSalones,300,"Salon3","Dirreccion3",0,2);
	hardcodeoSalones(listaSalones,400,"Salon4","Dirreccion4",1,3);
	hardcodeoSalones(listaSalones,500,"Salon5","Dirreccion5",0,4);

	hardcodeoArcades(listaArcades,100,"Nacionalidad1",1,2,23,5,"Los sims1",0);
	hardcodeoArcades(listaArcades,200,"Nacionalidad2",1,22,23,2,"Los sims",1);
	hardcodeoArcades(listaArcades,300,"Nacionalidad3",1,2,23,5,"Los sims3",2);
	hardcodeoArcades(listaArcades,400,"Nacionalidad4",1,23,23,3,"Los sims4",3);
	hardcodeoArcades(listaArcades,500,"Nacionalidad5",1,23,23,5,"Los sims",4);
	hardcodeoArcades(listaArcades,600,"Nacionalidad6",1,2,23,1,"Los sims6",5);
	hardcodeoArcades(listaArcades,700,"Nacionalidad7",1,23,23,4,"Los sims7",6);
	hardcodeoArcades(listaArcades,800,"Nacionalidad8",1,2,23,1,"Los sims8",7);
	hardcodeoArcades(listaArcades,900,"Nacionalidad9",1,23,23,5,"Los sims9",8);
	hardcodeoArcades(listaArcades,1000,"Nacionalidad10",1,1,23,5,"Los sims",9);
	hardcodeoArcades(listaArcades,1100,"Nacionalidad11",1,23,23,1,"Los sims",10);
	hardcodeoArcades(listaArcades,1200,"Nacionalidad12",1,1,23,5,"Los sims",11);
	hardcodeoArcades(listaArcades,1300,"Nacionalidad13",1,23,23,6,"Los sims5",12);
	hardcodeoArcades(listaArcades,1400,"Nacionalidad14",1,1,23,2,"Los sims",13);
	hardcodeoArcades(listaArcades,1500,"Nacionalidad15",1,23,23,3,"Los sims2",14);
	hardcodeoArcades(listaArcades,1600,"Nacionalidad16",1,1,23,5,"Los sims",15);




	
	while(salir == 0){
		printf("\n1) ALTA DE SALON \n2) ELIMINAR SALON \n3) IMPRIMIR SALONES \n4) INCORPORAR ARCADE \n5) MODIFICAR ARCADE \n6) ELIMINAR ARCADE \n7) IMPRIMIR ARCADES \n8) IMPRIMIR JUEGOS \n9) INFORMES\n10)SALIR");
		pedirStringEntero(&menu,"\nSelecionar -->", "No es una opcion valida",0,10, REINTENTOS);

		switch(menu){
			case 1:{
				if(crearSalon(listaSalones, CANTIDAD_SALONES,&AIIDSalones)==EXITO){
					flagSalones=1;
				}
				break;
			}
			case 2:{
				if(flagSalones==1){
					resultados=	eliminarSalon(listaSalones,CANTIDAD_SALONES,&borrarID);
					if(resultados!=-1 && resultados!=0){
					eliminarArcade(listaArcades, CANTIDAD_SALONES,borrarID);
					}
				}else{
					printf("No se a creado ningun salon aun");
				}
				break;
			}
			case 3:{
				if(flagSalones==1){
					imprimirSalones(listaSalones,CANTIDAD_SALONES,0);
				}else{
					printf("No se a creado ningun salon aun");
				}
				break;
			}
			case 4:{
				if(flagSalones==1){
					if(crearArcade(listaArcades,CANTIDAD_ARCADES,&AIIDArcades, listaSalones)==EXITO){
						flagArcades=1;
					}
				}else{
					printf("No se a creado ningun salon aun");
				}	
				break;
			}case 5:{
				if(flagArcades==1){
					modificarArcade(listaArcades, CANTIDAD_ARCADES);
				}else{
					printf("No se a creado ningun Arcade aun");
				}
				break;
			}case 6:{
				if(flagArcades==1){
					eliminarArcade(listaArcades, CANTIDAD_ARCADES,0);
				}else{
					printf("No se a creado ningun Arcade aun");
				}
				break;
			}case 7:{
				if(flagArcades==1){
					imprimirArcades(listaArcades, CANTIDAD_ARCADES);
				}else{
					printf("No se a creado ningun Arcade aun");
				}
				break;
			}case 8:{
				if(flagArcades==1){
					listarJuegos(listaArcades, CANTIDAD_ARCADES);
				}else{
					printf("No se a creado ningun Arcade aun");
				}
				break;
			}
			case 9:{
				if (flagArcades==1 && flagSalones==1)
				{
					/* code */
				
				
					printf("\n1) IMPRIMIR SALONES CON MAS DE 4 ARCADES \n2) IMPRIMIR TODOS LOS ARCADES PARA MAS DE 2 JUGADORES \n3) IMPRIMIR SALON INGRESANDO ID \n4) LISTAR ARCADE DE UN SALON \n5) IMPRIMIR SALON CON MAYOR CANTIDAD DE ARCADES \n6) IMPRIMIR MONTO TOTAL QUE PUDE FACTURAR UN SALON \n7) SABER CUANTOS ARCADES TIENEN EL JUEGO \n8) SALIR");

					pedirStringEntero(&submenu,"\nSelecionar -->", "No es una opcion valida",1,8, REINTENTOS);
					switch (submenu)
					{
					case 1:{

						cuatroArcades(listaSalones,CANTIDAD_SALONES,listaArcades,CANTIDAD_ARCADES);
						break;
					}
					case 2:{
						multiplayer(listaArcades,CANTIDAD_ARCADES,listaSalones,CANTIDAD_SALONES);

						break;
					}case 3:{
						salonPorId(listaSalones,CANTIDAD_SALONES,listaArcades,CANTIDAD_ARCADES);

						break;
					}case 4:{
						arcadesDelSalon(listaSalones,CANTIDAD_SALONES,listaArcades,CANTIDAD_ARCADES);

						break;
					}case 5:{
						mayorCantidadArcades(listaSalones,CANTIDAD_SALONES,listaArcades,CANTIDAD_ARCADES);

						break;
					}case 6:{
						montoMaximo(listaSalones,CANTIDAD_SALONES,listaArcades,CANTIDAD_ARCADES);

						break;
					}case 7:{
						buscarPorJuego(listaArcades,CANTIDAD_ARCADES);

						break;
					}case 8:{
						

						break;
					}
			
					
					default:
						break;
					}
					
				}else{
					printf("No se pueden realizar los informes dado que falta cargar algun Salon o Algun Arcade");
				}

				break;
			}
			case 10:{
				salir=1;
			}
			default:{

				break;
			}
		}

		system("\npause");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}


	return EXIT_SUCCESS;
}
