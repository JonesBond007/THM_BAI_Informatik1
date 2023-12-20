/*
	Project:	A91_Leerzeichen
	File:		main.c
	Author:		JonesBond007
	Date:		2023-12-20
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_VALUES 250

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

/*----Funktionsdeklarationen----*/
int countSpaces(char* text);

/*----Hauptprogramm----*/
int main() {
	char text[MAX_VALUES];
	int spaces;

	printf("Texteingabe: \n");
	gets(text);

	spaces = countSpaces(text);
	printf("Anzahl an Leerzeichen: %d\n", spaces);

	return 0;
}

int countSpaces(char* text) {
	int i, spaces;
	spaces = 0;

	for (i = 0; i < text[i] != '\0'; i++) {
		if (text[i] == ' ') {
			spaces++;
		}
	}

	return spaces;
}
