/*
	Project:	A81_Teiler (groesster gemeinsamer Teiler)
	File:		main.c
	Author:		JonesBond007
	Date:		2023-12-13
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*----Funktionsdeklarationen----*/
int ggT(int z1, int z2);

/*---Hauptprogramm----*/
int main() {
	int z1, z2;
	z1 = z2 = 0;
	printf("Bitte zwei natuerliche Zahlen eingeben:\n");
	printf("Zahl 1: ");
	scanf("%d", &z1);
	printf("Zahl 2: ");
	scanf("%d", &z2);
	
	if (z1 < 0 || z2 < 0) {
		printf("Programm abgebrochen. Bitte nur natuerliche Zahlen eingben.\n");
		return 0;
	}

	printf("\nDer groesste Gemeinsame Teiler von %d und %d ist: %d\n", z1, z2, ggT(z1, z2));
	return 0;
}

int ggT(int z1, int z2) {
	
	if (z1 == 0 && z2 == 0) {
		return 0;
	}
	else if (z1 == 0) {
		return z2;
	}
	else if (z2 == 0) {
		return z1;
	}

	return ggT(z2, z1 % z2);
}
