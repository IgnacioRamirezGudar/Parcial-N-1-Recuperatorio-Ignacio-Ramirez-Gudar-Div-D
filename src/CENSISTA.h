/*
 * CENSISTA.h
 *
 *  Created on: 21 may. 2022
 *      Author: ignac
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct{
	int legajoCensista;
	char nombre[51];
	int edad;
	int telefono;
}typedef CENSISTAS;




int addCen(CENSISTAS ListaCENSISTA[], int sizeArray, int legajo, char nombre[], int edad, char telefono[]);


#endif /* CENSISTA_H_ */
