/*
	Project:	A51_Potenzmethode
	File:		main.c
	Author:		JonesBond007
	Date:		2023-11-27
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	int Zahl, Ergebnis, Rest, Teiler;
	Zahl = 0;
	Rest = 0;
	Ergebnis = 0;
	Teiler = 128;
	
	for (;;) { //Endlosschleife
		printf("Bitte Dezimalzahl (max. 255) eingeben oder negative Zahl, um Programm zu beenden:\n");
		scanf("%d", &Zahl);

		if (Zahl < 0) { //Eingabebedingungen pruefen, bei negativer Zahl wird Programm beendet
			printf("Programm beendet.\n");
			return 0;
		}
		else if (Zahl >= Teiler*2) { // Bei zu grosser Zahl springt das Programm zurueck zur Eingabe
			printf("Zahl zu gross.\n");
			continue; //Sprung zurueck zum Schleifenkopf
		}

		printf("Binaerzahl:");

		for (Teiler; Teiler >= 1; Teiler = Teiler/2) { //Algoritmus zur Bestimmung der Binaerzahl
			Rest = Zahl % Teiler; //Bestimmung des Rests mittels Modulo %
			Ergebnis = (Zahl - Rest) / Teiler; //Um bei der Division auf das Ergebnis 1 oder 0 zu kommen, muss der Rest von der Zahl subtrahiert werden
			printf("%d", Ergebnis);
			Zahl = Rest;
		}
		printf("\n");
		printf("\n");
		Teiler = 128; //Teiler muss wieder auf 128 gesetzt werden, um das Programm nochmals auszuführen
	}
	return 0;
}
