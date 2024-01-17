/*
	Project:	A101_Rechner
	File:		main.c
	Author:		Jonas Fiegert
	Date:		2024-01-17
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*----Hauptprogramm----*/

int main(int argc, char* argv[]) {
	
	//Überprüfen, ob genügend Argumente übergeben worden sind
	if (argc < 4) {
		printf("ERROR: Fehlerhafte Eingabe.\n");
		return 1;
	}

	//-h: Ausgabe der Programmbeschreibung
	if (strcmp(argv[1], "-h") == 0) {
		printf("Taschenrechner (Grundrechenarten) fuer die Kommandozeile.\n");
		printf("Aufruf: rechner <Wert1> <Operator> <Wert2>\n");
		return 0;
	}

	//Einlesen der Werte
	/*
		Hinweis zur Funktion sscanf:
		sscanf wandelt i.d.F. die Eingabewerte in Fließkommazahlen um.
		Dabei wird die Anzahl der erfolgreich übereinstimmenden Werte zurückgegeben.
		Es wird daher geprüft, ob jeweils genau 1 Wert erfolgreich eingelesen wurde.
	*/
	double val1, val2;
	if (sscanf(argv[1], "%lf", &val1) != 1 || sscanf(argv[3], "%lf", &val2) != 1) {
		printf("ERROR: Fehlerhafte Eingabe.\n");
		return 1;
	}

	char operator;
	operator = argv[2][0];
	double res;

	switch (operator) {
		case '+':
			res = val1 + val2;
			break;

		case '-':
			res = val1 - val2;
			break;

		case '*':
			res = val1 * val2;
			break;

		case '/':
			if (val2 == 0) { // Überprüfen ob Division durch 0
				printf("ERROR: Mathematischer Fehler (Divisoion durch 0).\n");
				return 1;
			}
			res = val1 / val2;
			break;

		default:
			printf("ERROR: Ungueltiger Operator.\n");
	}

	printf("Ergebnis: %.2f\n", res);

	return 0;
}