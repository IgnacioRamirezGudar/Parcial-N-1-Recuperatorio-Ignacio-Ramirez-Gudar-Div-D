/*
 * CENSISTA.c
 *
 *  Created on: 22 jun. 2022
 *      Author: ignac
 */

#include "CENSISTA.h"
#include "input-UTN.h"

int addCen(CENSISTAS ListaCENSISTA[], int sizeArray, int legajo, char nombre[], int edad, char telefono[]){

	CENSISTAS NewCENSISTA;

	char tel[15];

	NewCENSISTA.legajoCensista = legajo;
	strcpy(NewCENSISTA.nombre,nombre);
	NewCENSISTA.edad = edad;
	strcpy(tel,telefono);
	NewCENSISTA.telefono = atoi(tel);

	ListaCENSISTA[sizeArray] = NewCENSISTA;

	return 0;
}
