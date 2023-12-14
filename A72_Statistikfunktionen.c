/*
	Project:	A72_Statistikfunktionen
	File:		main.c
	Author:		JonesBond007
	Date:		2023-12-06
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_VALUES 100
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*----Funktionsdeklarationen----*/
int readValues (void);
double mean (void);
double maximum(void);
double minimum(void);
void setLength(int input);
int returnLength(void);
double variance(void);
double standardDeviation(void);


/*----globale Variablen----*/
double measurements[MAX_VALUES];
int length = 0;

/*----Hauptprogramm----*/

int main() {
	int input = 0;
	int n = 1; //Prüfvariable, ob Messwerte eingegeben worden sind
	double meV, min, max, sDev, var;

	for (;;) {
		printf("Messwertanalyse\n===============\n");
		printf("\nMenue:\n");
		printf("1 - Messwerte eingeben\n");
		printf("2 - Mittelwert bestimmen\n");
		printf("3 - Maximum bestimmen\n");
		printf("4 - Minimum bestimmen\n");
		printf("5 - Varianz bestimmen\n");
		printf("6 - Standardabweichung bestimmen\n");
		printf("7 - Anzahl der Messwerte angeben\n");
		printf("0 - Programm beenden\n");

		scanf("%d", &input);
		if (input > 7) {
			printf("Unzulaessiger Aufruf.\n\n");
			continue;
		}

		switch (input) {
		case 0:
			printf("Programm beendet.\n");
			return 0;

		case 1:
			n = readValues();
			printf("\n");
			break;

		case 2:
			if (n == 0) { // prüfen, ob Messerwerte eingegeben worden sind --> wenn keine eingeben worden sind, dann ist n = 1
				meV = mean();
				printf("Mittelwert = %lf\n\n", meV);
			}
			else {
				printf("Bitte Messwerte einlesen.\n\n");
			}
			break;

		case 3:
			if (n == 0) {
				max = maximum();
				printf("Maximum = %lf\n\n", max);
			}
			else {
				printf("Bitte Messwerte einlesen.\n\n");
			}
			break;

		case 4:
			if (n == 0) {
				min = minimum();
				printf("Minimum = %lf\n\n", min);
			}
			else {
				printf("Bitte Messwerte einlesen.\n\n");
			}
			break;

		case 5: //nicht verlangt in Aufgabenstellung
			if (n == 0) {
				var = variance();
				printf("Varianz = %lf\n\n", var);
			}
			else {
				printf("Bitte Messwerte einlesen.\n\n");
			}
			break;

		case 6:
			if (n == 0) {
				sDev = standardDeviation();
				printf("Standardabweichung = %lf\n\n", sDev);
			}
			else {
				printf("Bitte Messwerte einlesen.\n\n");
			}
			break;

		case 7: //nicht verlangt in Aufgabenstellung
			printf("Anzahl an Messwerten: %d\n\n", returnLength());
			break;
		}
	}

	return 0;
}

void setLength(int input) {
	length = input;
	return;
}

int returnLength(void) {
	return length;
}

int readValues(void) {
	double value;
	int anzahl;

	printf("Anzahl der Messwerte eingeben:\n");
	scanf("%d", &anzahl);
	if (anzahl > MAX_VALUES) anzahl = MAX_VALUES;

	printf("Messwerte eingeben:\n");

	int i;
	for (i = 0; i < anzahl; i++) {
		scanf("%lf", &value);
		measurements[i] = value;
	}

	setLength(i); //nicht i+1, da i nach dem letzten Schleifendurchlauf 'anzahl' entspricht
	return 0; //n wird hiermit auf 0 gesetzt 
}

double mean(void) {
	if (length == 0) {
		printf("FEHLER! - DIVISION DURCH 0\n\n");
		return -1;
	}

	double sum = 0;
	int i;
	for (i = 0; i < MAX_VALUES; i++) {
		sum = sum + measurements[i];
	}
	
	double meV = sum / length;
	return meV;
}

double maximum(void) {
	int i;
	double max = measurements[0];
	for (i = 1; i < length; i++) {
		if (max < measurements[i]) {
			max = measurements[i];
		}
	}

	return max;
}

double minimum(void) {
	int i;
	double min = measurements[0];
	printf("%lf\n", min);
	for (i = 1; i < length; i++) {
		if (min > measurements[i]) {
			min = measurements[i];
			printf("%lf\n", min);
		}
	}

	return min;
}

double variance(void) {
	double meV = mean();
	double sqsum = 0;
	int i;
	for (i = 0; i < length; i++) {
		sqsum += pow(measurements[i] - meV, 2); //Berechnung der Quadratsumme (x_i - Mittelwert)^2
	}
	double var = sqsum / length;
	return var;
}

double standardDeviation(void) {
	double sDev = sqrt(variance());
	return sDev;
}
