/*
 * VIVIENDA.C
 *
 *  Created on: 22 jun. 2022
 *      Author: ignac
 */


#include "VIVIENDA.h"
#include "input-UTN.h"


static int valId = 20000;

static int valId2 = 0;

int generateId(){

	valId++;

	return valId;
}

int generateId2(){

	valId2++;

	return valId2;
}



int addVIVIENDA(VIVIENDAS* ListaCENSONACIONAL[],int sizeArray,char streat[], int cantPersons, int cantRooms, int typeApartment, int legCen){

	ListaCENSONACIONAL[sizeArray]->id = generateId();
	strcpy(ListaCENSONACIONAL[sizeArray]->street,streat);
	ListaCENSONACIONAL[sizeArray]->cantPersons = cantPersons;
	ListaCENSONACIONAL[sizeArray]->cantRooms = cantRooms;
	ListaCENSONACIONAL[sizeArray]->typeApartment = typeApartment;
	ListaCENSONACIONAL[sizeArray]->legCen = legCen;

	return 0;
}

int addCATASTRO(CATASTROS* listaCATASTRO[], int LongArray3, char localidad[], char manzana[], char parcela[]){


	listaCATASTRO[LongArray3]->idCatastro = generateId2();
	strcpy(listaCATASTRO[LongArray3]->localidad,localidad);
	strcpy(listaCATASTRO[LongArray3]->manzana,manzana);
	strcpy(listaCATASTRO[LongArray3]->parcela,parcela);

	return 0;
}

int modVIVIENDA(VIVIENDAS* ListaCENSONACIONAL[], int sizeArray, int id){

	VIVIENDAS changeNewDataVIVIENDA;

	char typeApartment[51];
	char newstreat[25];
	int opcion;
	int newcantPersons;
	int newcantRooms;
	int newType;

	for(int i = sizeArray; i <= sizeArray; i++){
		if(ListaCENSONACIONAL[i]->id == id){
			if(ListaCENSONACIONAL[i]->typeApartment == 1){
				strcpy(typeApartment , "CASA");
			}else {
				if(ListaCENSONACIONAL[i]->typeApartment == 2){
					strcpy(typeApartment , "DEPARTAMENTO");
				}else {
					if(ListaCENSONACIONAL[i]->typeApartment == 3){
						strcpy(typeApartment , "CASILLA");
					}else {
						if(ListaCENSONACIONAL[i]->typeApartment == 4){
							strcpy(typeApartment , "RANCHO");
						}
					}
				}
			}

			printf("\n==================CENSO NACIONAL 2022 / VIVIENDA A MODIFICAR======================");
			printf("\nID: %d", ListaCENSONACIONAL[i]->id);
			printf("\nCALLE: %s", ListaCENSONACIONAL[i]->street);
			printf("\nCANT PERSONAS: %d", ListaCENSONACIONAL[i]->cantPersons);
			printf("\nCANT HABITACIONES: %d", ListaCENSONACIONAL[i]->cantRooms);
			printf("\nTIPO: %s", typeApartment);
			printf("\nLEGAJO: %d", ListaCENSONACIONAL[i]->legCen);
			if(UTN_getNumero(&opcion,"\n==================================================================================="
					"\n1) Cambiar datos de la calle"
					"\n2) Cambiar la cantidad de personas que viven"
					"\n3) Cambiar la cantidad de habitaciones que hay"
					"\n4) Cambiar el tipo de vivienda"
					"\n5) SALIR"
					"\nELIGA UNA OPCION: ","\nERROR...ELIGA UNA OPCION VALIDA",1,5,10) == 0){

				switch(opcion){
					case 1:
							UTN_getAlfaNum(newstreat,25,"\n-INGRESE NUEVA CALLE Y DIRECCION DE LA CASA: ","\nERROR AL INTRODUCIR CALLE O DIRECCION DE LA CASA", 5);

							strcpy(ListaCENSONACIONAL[i]->street,newstreat);

						break;
					case 2:
							UTN_getNumero(&newcantPersons,"\n-NUEVA CANTIDAD DE PERSONAS QUE VIVEN EN LA CASA: ","\nERROR AL INGRESAR LA CANTIDAD DE PERSONAS",1,10,5);

							ListaCENSONACIONAL[i]->cantPersons = newcantPersons;

						break;
					case 3:
							UTN_getNumero(&newcantRooms,"\n-NUEVA CANTIDAD DE HABITACIONES: ","\nERROR AL INGRESAR LA CANTIDAD DE HABITACIONES",1,10,5);

							ListaCENSONACIONAL[i]->cantRooms = newcantRooms;

						break;
					case 4:
							UTN_getNumeroRange(&newType,"\n|1.CASA\t|\t2.DEPARTAMENTO\t|\t3.CASILLA\t|\t4.RANCHO| \nELIGA SU TIPO DE VIVIENDA: ","\nERROR AL ELEGIR EL TIPO DE VIVIENDA",1,4,5);

							ListaCENSONACIONAL[i]->typeApartment = newType;

						break;
					default:
						return 0;
						break;
				}
			}

			changeNewDataVIVIENDA.id = ListaCENSONACIONAL[i]->id;
			strcpy(changeNewDataVIVIENDA.street,ListaCENSONACIONAL[i]->street);
			changeNewDataVIVIENDA.cantPersons = ListaCENSONACIONAL[i]->cantPersons;
			changeNewDataVIVIENDA.cantRooms = ListaCENSONACIONAL[i]->cantRooms;
			changeNewDataVIVIENDA.typeApartment = ListaCENSONACIONAL[i]->typeApartment;
			changeNewDataVIVIENDA.legCen = ListaCENSONACIONAL[i]->legCen;
			//ListaCENSONACIONAL[sizeArray] = changeNewDataVIVIENDA;
		}
	}

	return 0;
}

int showlistVIVIENDA(VIVIENDAS* ListaCENSONACIONAL[], int tamARRAY, CATASTROS* listaCATASTRO[], int LongArray3){

	char typeApartment[51];

	printf("\n\t\t\t\t\t    LISTA DE VIVIENDAS");
	printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
	printf("\n|ID\t|\tCALLE\t|\tCANTIDAD DE PERSONAS\t|\tCANTIDAD DE HABITACIONES\t\t|\tTIPO DE VIVIENDA\t|\tLEGAJO\t|IDCATASTRO|LOCALIDAD|MANZANA|PARCELA");
	printf("\n|=======================================================================================================================================================|");

	for(int i = 1; i <= tamARRAY; i++){
		if(ListaCENSONACIONAL[i]->id > 0){
			if(ListaCENSONACIONAL[i]->typeApartment == 1){
										strcpy(typeApartment , "CASA");
									} else {
										if(ListaCENSONACIONAL[i]->typeApartment == 2){
											strcpy(typeApartment , "DEPARTAMENTO");
										} else {
											if(ListaCENSONACIONAL[i]->typeApartment == 3){
												strcpy(typeApartment , "CASILLA");
											}  else {
												if(ListaCENSONACIONAL[i]->typeApartment == 4){
													strcpy(typeApartment , "RANCHO");
												}
											}
										}
									}
			printf("\n|%d\t|\t%s\t|\t\t%d\t\t|\t\t%d\t\t\t\t|\t%s\t\t\t|\t%d\t|%d\t|%s\t|%s\t|%s|", ListaCENSONACIONAL[i]->id, ListaCENSONACIONAL[i]->street,ListaCENSONACIONAL[i]->cantPersons,ListaCENSONACIONAL[i]->cantRooms,typeApartment,ListaCENSONACIONAL[i]->legCen,listaCATASTRO[i]->idCatastro,listaCATASTRO[i]->localidad,listaCATASTRO[i]->manzana,listaCATASTRO[i]->parcela);
			printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
		}
	}

	return 0;
}


int lowVIVIENDA(VIVIENDAS ListaCENSONACIONAL[], int sizeArray, int id){

	char opcion[51];

	for(int i = sizeArray; i <= sizeArray; i++){

		if(id == ListaCENSONACIONAL[i].id){
			printf("\n==================CENSO NACIONAL 2022 / CONFIRMAR BAJA DE VIVIENDA======================");
			printf("\nDESEA BAJAR LA SIGUIENTE ID [%d] ? (ACEPTAR / CANCELAR)", ListaCENSONACIONAL[i].id);
			fflush(stdin);
			gets(opcion);
			if(strcmp(opcion,"ACEPTAR") == 0 || strcmp(opcion,"aceptar") == 0){
				ListaCENSONACIONAL[i].id = 0;
				return 0;
			} else{
				if(strcmp(opcion,"CANCELAR") == 0 || strcmp(opcion,"cancelar") == 0){
					return 0;
				}
			}

		}
	}

	return 0;
}

