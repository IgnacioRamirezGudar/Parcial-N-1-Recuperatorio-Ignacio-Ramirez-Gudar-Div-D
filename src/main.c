/*
 ============================================================================
 Name        : main.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input-UTN.h"
#include "VIVIENDA.h"
#include "CENSISTA.h"

static int TAMARRAY = 0;
static int TAMARRAY2 = 0;
static int TAMARRAY3 = 0;

int arrray(){

	TAMARRAY++;

	return TAMARRAY;
}

int arrray2(){

	TAMARRAY2++;

	return TAMARRAY2;
}

int arrray3(){

	TAMARRAY3++;

	return TAMARRAY3;
}



int ADDVIVIENDA(VIVIENDAS ListaCENSONACIONAL[],int tamARRAY, CENSISTAS ListaCENSISTA[], int tamARRAY2, CATASTROS listaCATASTRO[], int LongArray3);
int modiVIVIENDA(VIVIENDAS ListaCENSONACIONAL[], int tamARRAY);
int lowerVIVIENDA(VIVIENDAS ListaCENSONACIONAL[], int tamARRAY);
int listVIVIENDA(VIVIENDAS ListaCENSONACIONAL[], int tamARRAY, CATASTROS listaCATASTRO[], int LongArray3);
int listCENSISTA(VIVIENDAS ListaCENSONACIONAL[],int tamARRAY, CENSISTAS ListaCENSISTA[], int tamARRAY2);
int LISTARCATASTRO(VIVIENDAS ListaCENSONACIONAL[],int tamARRAY, CENSISTAS ListaCENSISTA[], int tamARRAY2, CATASTROS listaCATASTRO[], int LongArray3);

int main(void) {

	setbuf(stdout, NULL);

	VIVIENDAS ListaCENSONACIONAL[TAMARRAY];

	CENSISTAS ListaCENSISTA[TAMARRAY2];

	CATASTROS listaCATASTRO[TAMARRAY3];

	int opciones;
	int LongArray;
	int LongArray2;
	int LongArray3;


	do{
		printf("\n==================CENSO NACIONAL 2022==================");
		if(UTN_getNumero(&opciones,"\n1) ALTA VIVIENDA"
								"\n2) MODIFICAR VIVIENDA"
								"\n3) BAJA VIVIENDA"
								"\n4) LISTAR VIVIENDA"
								"\n5) LISTAR CENSISTAS"
								"\n6) LISTAR CATASTRO-ORDENADO POR LOCALIDAD"
								"\n7) SALIR"
								"\n------------------------"
								"\nSELECCIONE UNA OPCION: ","\n ERROR...ELIGA UNA OPCION VALIDA",1,7,5) == 0){
				switch(opciones){
						case 1:
							LongArray = arrray();
							LongArray2 = arrray2();
							LongArray3 = arrray3();
							ADDVIVIENDA(ListaCENSONACIONAL,LongArray, ListaCENSISTA, LongArray2, listaCATASTRO, LongArray3);
							break;
						case 2:
							modiVIVIENDA(ListaCENSONACIONAL,LongArray);
							break;
						case 3:
							lowerVIVIENDA(ListaCENSONACIONAL,LongArray);
							break;
						case 4:
							listVIVIENDA(ListaCENSONACIONAL,LongArray, listaCATASTRO, LongArray3);
							break;
						case 5:
							listCENSISTA(ListaCENSONACIONAL,LongArray, ListaCENSISTA, LongArray2);
							break;
						case 6:
							LISTARCATASTRO(ListaCENSONACIONAL,LongArray, ListaCENSISTA, LongArray2,listaCATASTRO, LongArray3);
							break;
						default:
							return 0;
							break;
			}
		}

	}while( opciones != 7);

	return 0;
}

int ADDVIVIENDA(VIVIENDAS ListaCENSONACIONAL[],int tamARRAY, CENSISTAS ListaCENSISTA[], int tamARRAY2, CATASTROS listaCATASTRO[], int LongArray3){

	VIVIENDAS auxVIVIENDAS;
	CENSISTAS auxCENSISTAS;
	CATASTROS auxCATASTROS;

	char telefono[15];


	if(UTN_getAlfaNum(auxVIVIENDAS.street,25,"\n-INGRESE CALLE Y DIRECCION DE LA CASA: ","\nERROR AL INTRODUCIR CALLE O DIRECCION DE LA CASA", 5)){
		if(UTN_getNumero(&auxVIVIENDAS.cantPersons,"\n-CANTIDAD DE PERSONAS QUE VIVEN EN LA CASA: ","\nERROR AL INGRESAR LA CANTIDAD DE PERSONAS",1,10,5) == 0){
			if(UTN_getNumero(&auxVIVIENDAS.cantRooms,"\n-CANTIDAD DE HABITACIONES QUE HAY EN LA CASA: ","\nERROR AL INGRESAR LA CANTIDAD DE HABITACIONES", 1,10,5) == 0){
				if(UTN_getNumeroRange(&auxVIVIENDAS.typeApartment,"\n|1.CASA\t|\t2.DEPARTAMENTO\t|\t3.CASILLA\t|\t4.RANCHO| \nELIGA SU TIPO DE VIVIENDA: ","\nERROR AL ELEGIR EL TIPO DE VIVIENDA",1,4,5) == 1){
					if(UTN_getNumero(&auxVIVIENDAS.legCen,"\n-INGRESE UN LEGAJO (LEGAJO CENSISTA): ","\nERROR AL INGRESAR EL NUMERO DEL LEGAJO",1,1000000,5) == 0){
						if(UTN_getAlfaNum(auxCATASTROS.localidad, 51,"\n INGRESE LA LOCALIDAD EN DONDE VIVE: ","\n ERROR AL INGRESAR LA LOCALIDAD",5)){
							if(UTN_getAlfaNum(auxCATASTROS.manzana, 25, "\n INGRESE LA MANZANA: ", "\n ERROR AL INGRESAR LA MANZANA", 5)){
								if(UTN_getAlfaNum(auxCATASTROS.parcela, 25, "\n INGRESE LA PARCELA DE SU CASA: ", "\n ERROR AL INGRESAR LA PARCELA", 5)){
									if(UTN_getString(auxCENSISTAS.nombre,51,"\n-INGRESE NOMBRE DEL ENCARGADO DE LA CASA: ","\n ERROR...AL INGRESAR ESE NOMBRE",10)){
										if(UTN_getNumero(&auxCENSISTAS.edad,"\n-INGRESE LA EDAD DEL CENSISTA: ","\nERROR... AL INGRESAR LA EDAD",20,100,5) == 0){
											if(UTN_getAlfaNum(telefono,15,"\n-INGRESE NUMERO DE TELEFONO DEL CENSISTA: ","\nERROR... AL INGRESAR EL N° TELEFONO",10)){
												addCen(ListaCENSISTA, tamARRAY2, auxVIVIENDAS.legCen,auxCENSISTAS.nombre,auxCENSISTAS.edad,telefono);
												addVIVIENDA(ListaCENSONACIONAL,tamARRAY,auxVIVIENDAS.street,auxVIVIENDAS.cantPersons,auxVIVIENDAS.cantRooms,auxVIVIENDAS.typeApartment,auxVIVIENDAS.legCen);
												addCATASTRO(listaCATASTRO, LongArray3, auxCATASTROS.localidad, auxCATASTROS.manzana, auxCATASTROS.parcela);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}

int modiVIVIENDA(VIVIENDAS ListaCENSONACIONAL[], int tamARRAY){

	int id;

	printf("\n==================CENSO NACIONAL 2022 / MODIFICAR VIVIENDA==================");
	if(UTN_getNumero(&id,"\n- INGRESE ID DE LA VIVIENDA QUE DESEA MODIFICAR (rango de ID apartir desde 20001): ","\nERROR AL INGRESAR LA ID",20001,ListaCENSONACIONAL->id,10) == 0){

		modVIVIENDA(ListaCENSONACIONAL, tamARRAY, id);

	}

	return 0;
}

int lowerVIVIENDA(VIVIENDAS ListaCENSONACIONAL[], int tamARRAY){

	int id;

	printf("\n==================CENSO NACIONAL 2022 / BAJAR VIVIENDA==================");
	if(UTN_getNumero(&id,"\n- INGRESE ID DE LA VIVIENDA QUE DESEA BAJAR (rango de ID apartir desde 20001): ","\nERROR AL INGRESAR LA ID",20001,ListaCENSONACIONAL->id,10) == 0){

		lowVIVIENDA(ListaCENSONACIONAL, tamARRAY, id);

	}

	return 0;
}

int listVIVIENDA(VIVIENDAS ListaCENSONACIONAL[], int tamARRAY, CATASTROS listaCATASTRO[], int LongArray3){

	showlistVIVIENDA(ListaCENSONACIONAL, tamARRAY, listaCATASTRO, LongArray3);

	return 0;
}

int listCENSISTA(VIVIENDAS ListaCENSONACIONAL[],int tamARRAY, CENSISTAS ListaCENSISTA[], int tamARRAY2){

	for(int i = 1; i <= tamARRAY; i++){
		if(ListaCENSONACIONAL[i].id > 0){
				printf("\n|%d\t|\t%s\t|\t\t%d\t\t|\t\t%d\t\t\t\t|", ListaCENSISTA[i].legajoCensista, ListaCENSISTA[i].nombre,ListaCENSISTA[i].edad,ListaCENSISTA[i].telefono);
				printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
		}
	}

	return 0;
}

int LISTARCATASTRO(VIVIENDAS ListaCENSONACIONAL[],int tamARRAY, CENSISTAS ListaCENSISTA[], int tamARRAY2, CATASTROS listaCATASTRO[], int LongArray3){


	int opciones;
	char typeApartment[51];
	int tipoDeVivienda;
	char localidad[51];
	int contLocalidad = 0;
	int contCASAS = 0;
	int contDEPARTAMENTO = 0;

	UTN_getNumero(&opciones, "\n1)Elegir un tipo de vivienda y mostrar todos los datos de la vivienda, nombre del censista y datos de catastro del tipo seleccionado."
							"\n2)Elegir una Localidad y mostrar todos los datos de la vivienda y nombre del censista de la Localidad seleccionada"
							"\n3)Cantidad de viviendas censadas en la localidad de Avellaneda"
							"\n4)Elegir un censista y mostrar todas las viviendas que censó con los datos de catastro."
							"\n5)Cantidad de viviendas de tipo “casa” censadas."
							"\n6)Cantidad de viviendas de tipo “departamento” de la localidad de Lanús."
							"\n7)SALIR"
							"\nELIGA UNA OPCION: ", "\n ERROR AL ELEGIR UNA OPCION",1,7,10);

	switch(opciones){
		case 1:
			if(UTN_getNumeroRange(&tipoDeVivienda,"\n|1.CASA\t|\t2.DEPARTAMENTO\t|\t3.CASILLA\t|\t4.RANCHO| \nELIGA SU TIPO DE VIVIENDA: ","\nERROR AL ELEGIR EL TIPO DE VIVIENDA",1,4,5) == 1){
				printf("\n\t\t\t\t\t    LISTA DE VIVIENDAS");
				printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
				printf("\n|ID\t|\tCALLE\t|\tCANTIDAD DE PERSONAS\t|\tCANTIDAD DE HABITACIONES\t\t|\tTIPO DE VIVIENDA\t|\tLEGAJO\t|IDCATASTRO|LOCALIDAD|MANZANA|PARCELA|NOMBRE CENSISTA");
				printf("\n|=======================================================================================================================================================|");
				for(int i = 1; i <= tamARRAY; i++){
					if(ListaCENSONACIONAL[i].typeApartment == tipoDeVivienda){
						if(ListaCENSONACIONAL[i].typeApartment == 1){
							strcpy(typeApartment , "CASA");
						} else {
							if(ListaCENSONACIONAL[i].typeApartment == 2){
								strcpy(typeApartment , "DEPARTAMENTO");
							} else {
								if(ListaCENSONACIONAL[i].typeApartment == 3){
									strcpy(typeApartment , "CASILLA");
								}  else {
									if(ListaCENSONACIONAL[i].typeApartment == 4){
										strcpy(typeApartment , "RANCHO");
									}
								}
							}
						}
						printf("\n|%d\t|\t%s\t|\t\t%d\t\t|\t\t%d\t\t\t\t|\t%s\t\t\t|\t%d\t|%d\t|%s\t|%s\t|%s\t|\t%s|", ListaCENSONACIONAL[i].id, ListaCENSONACIONAL[i].street,ListaCENSONACIONAL[i].cantPersons,ListaCENSONACIONAL[i].cantRooms,typeApartment,ListaCENSONACIONAL[i].legCen,listaCATASTRO[i].idCatastro,listaCATASTRO[i].localidad,listaCATASTRO[i].manzana,listaCATASTRO[i].parcela,ListaCENSISTA[i].nombre);
						printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
					}
				}
			}
			break;
		case 2:
			if(UTN_getAlfaNum(localidad, 51,"\n INGRESE LA LOCALIDAD EN DONDE VIVE: ","\n ERROR AL INGRESAR LA LOCALIDAD",5)){
				fflush(stdin);
				printf("\n\t\t\t\t\t    LISTA DE VIVIENDAS");
				printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
				printf("\n|ID\t|\tCALLE\t|\tCANTIDAD DE PERSONAS\t|\tCANTIDAD DE HABITACIONES\t\t|\tTIPO DE VIVIENDA\t|\tLEGAJO\t|IDCATASTRO|LOCALIDAD|MANZANA|PARCELA|NOMBRE CENSISTA");
				printf("\n|=======================================================================================================================================================|");
				for(int i = 1; i <= LongArray3 ; i++){
					if(strcmp(listaCATASTRO[i].localidad,localidad) == 0){
						if(ListaCENSONACIONAL[i].typeApartment == tipoDeVivienda){
							if(ListaCENSONACIONAL[i].typeApartment == 1){
								strcpy(typeApartment , "CASA");
							} else {
								if(ListaCENSONACIONAL[i].typeApartment == 2){
									strcpy(typeApartment , "DEPARTAMENTO");
								} else {
									if(ListaCENSONACIONAL[i].typeApartment == 3){
										strcpy(typeApartment , "CASILLA");
									}  else {
										if(ListaCENSONACIONAL[i].typeApartment == 4){
											strcpy(typeApartment , "RANCHO");
										}
									}
								}
							}
							printf("\n|%d\t|\t%s\t|\t\t%d\t\t|\t\t%d\t\t\t\t|\t%s\t\t\t|\t%d\t|%s\t|\t%s|", ListaCENSONACIONAL[i].id, ListaCENSONACIONAL[i].street,ListaCENSONACIONAL[i].cantPersons,ListaCENSONACIONAL[i].cantRooms,typeApartment,ListaCENSONACIONAL[i].legCen,listaCATASTRO[i].localidad,ListaCENSISTA[i].nombre);
							printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
						}
					}
				}
			}
			break;
		case 3:
				for(int i = 1; i <= LongArray3 ; i++){
					if(strcmp(listaCATASTRO[i].localidad,"AVELLANEDA") == 0 || strcmp(listaCATASTRO[i].localidad,"avellaneda") == 0){
						contLocalidad++;
					}
				}
				printf("La cantidad viviendad censadas en Avellaneda son : %d" ,contLocalidad);
			break;
		case 4:
			//NO REALIZADO
			return 0;
			break;
		case 5:
				for(int i = 1; i <= tamARRAY ; i++){
					if(ListaCENSONACIONAL[i].typeApartment == 1){
						contCASAS++;
					}
				}
				printf("La cantidad de casas censadas son : %d" ,contCASAS);
			break;
		case 6:
			for(int i = 1; i <= tamARRAY ; i++){
				if(ListaCENSONACIONAL[i].typeApartment == 2){
					contDEPARTAMENTO++;
				}
			}
			printf("La cantidad de departamentos censados son : %d" ,contDEPARTAMENTO);
			break;
		default:
			return 0;
			break;
	}

	return 0;
}
