/*
	Project:	A52_Textzeile
	File:		main.c
	Author:		JonesBond007
	Date:		2023-11-29
*/

#define _CRT_SCECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char c;
	char text[41];
	int length = 40;
	int i = 0;

	printf("Texteingabe (max. %d Zeichen):\n", length);
	
	do {
		c = getchar();
		text[i] = c;
		i++;
	} while (c != '\n' && i <= length);

	printf("\nTextausgabe:\n");

	for (int j = 0; j < i; j++) {
		printf("%c", text[j]);
	}
	
	return 0;
}
