/*
 * CENSISTA.c
 *
 *  Created on: 22 jun. 2022
 *      Author: ignac
 */

#include "CENSISTA.h"
#include "input-UTN.h"

int addCen(CENSISTAS ListaCENSISTA[], int sizeArray, int legajo, char nombre[], int edad, int telefono){

	CENSISTAS NewCENSISTA;

	NewCENSISTA.legajoCensista = legajo;
	strcpy(NewCENSISTA.nombre,nombre);
	NewCENSISTA.edad = edad;
	NewCENSISTA.telefono = telefono;

	ListaCENSISTA[sizeArray] = NewCENSISTA;

	return 0;
}
