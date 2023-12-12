/*
	Project:	A53_Pascalsches_Dreieck
	File:		main.c
	Author:		Jonas Fiegert
	Date:		2023-11-29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int size;
	printf("Groesse eingeben:\n");
	scanf("%d", &size);
	if (size < 2) size = 2;		// mind. 2, sonst macht das Dreieck keinen Sinn
	if (size > 13) size = 13;	//max. 13, da ab 14. Ebene bereits 4-stellige Zahlen ausgegeben werden
	printf("Pascal'sche Dreieck der Groesse %d:\n\n", size);
	
	/*Initialisierung der  Dreiecksmatrix*/
	int dreieck[15][15];

	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (x == 0) {
				dreieck[x][y] = 1;
			}
			else {
				dreieck[x][y] = 0;
			}

		}
	}

	/*Algorithmus*/
	for (int y = 1; y < size; y++) {
		for (int x = 1; x < size; x++) {
			dreieck[x][y] = dreieck[x - 1][y - 1] + dreieck[x][y - 1];
		}
	}

	/*Ausgabe der Matrix*/
	for (int y = 0; y < size; y++) {
		for (int i = 0; i < ((size-y-1)*2); i++) {
			printf(" ");
		}
		for (int x = 0; x < size; x++) {
			if (dreieck[x][y] != 0) printf("%4d", dreieck[x][y]);
		}
		printf("\n");
	}

	return 0;
}
