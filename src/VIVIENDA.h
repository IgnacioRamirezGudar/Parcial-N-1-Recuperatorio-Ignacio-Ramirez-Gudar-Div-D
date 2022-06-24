/*
 * VIVIENDA.h
 *
 *  Created on: 20 may. 2022
 *      Author: ignac
 */

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct{
	int id;
	char street[25];
	int cantPersons;
	int cantRooms;
	int typeApartment;
	int legCen;
}typedef VIVIENDAS;

struct{
	int id;
}typedef IDBAJAS;

struct{
	int idCatastro;
	char localidad[51];
	char manzana[25];
	char parcela[25];
}typedef CATASTROS;




int addVIVIENDA(VIVIENDAS* ListaCENSONACIONAL[], int sizeArray, char streat[], int cantPersons, int cantRooms, int typeApartment, int legCen);

int addCATASTRO(CATASTROS* listaCATASTRO[], int LongArray3, char localidad[], char manzana[], char parcela[]);

int modVIVIENDA(VIVIENDAS* ListaCENSONACIONAL[], int sizeArray, int id);

int showlistVIVIENDA(VIVIENDAS* ListaCENSONACIONAL[], int tamARRAY, CATASTROS* listaCATASTRO[], int LongArray3);

int lowVIVIENDA(VIVIENDAS ListaCENSONACIONAL[], int sizeArray, int id);


#endif /* VIVIENDA_H_ */
