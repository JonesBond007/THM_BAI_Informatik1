/*
	Project:	A92_Zeichenkette_suchen
	File:		main.c
	Author:		Jonas Fiegert
	Date:		2024-01-16
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_VALUES_T 80
#define MAX_VALUES_S 10

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

/*----Funktionsdeklarationen----*/
int sucheText(char* text, char* suchwort);

/*----Hauptprogramm----*/
int main() {
	char text[MAX_VALUES_T];
	printf("Texteingabe:\n");
	gets(text);

	char suchwort[MAX_VALUES_S];
	printf("Suchwort eingeben:\n");
	gets(suchwort);

	int position = sucheText(text, suchwort);

	if ( position == -1) {
		printf("Suchwort nicht gefunden!\n");
	}
	else {
		printf("%s wurde gefunden an Stelle: %d\n", suchwort, position);
	}
}

int sucheText(char* text, char* suchwort) {
	int index1, index2;
	
	for (index1 = 0; text[index1] != '\0'; index1++) {
		for (index2 = 0; suchwort[index2] != '\0'; index2++) {
			if (text[index1 + index2] != suchwort[index2]) {
				break;
			}
		}
		if (suchwort[index2] == '\0') {
			return index1; //Suchwort gefunden
		}
	}
	return -1; //Suchwort nicht gefunden
}