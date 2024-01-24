/*
	Das Programm soll maximal 100 Spannungswerte einlesen und anschlieﬂend
	den Mittelwert berechnen und ausgeben. Der Quelltext enth‰lt jedoch 6 Fehler.
	Aufgabenstellung:
	Korrigieren Sie die Fehler und laden Sie den korrigierten Quelltext
	in Moodle hoch!
*/

# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

# define MAX 100

int main()
{
	int i, anzahl;
	double daten[MAX], summe=0, mittelwert;

	printf("Maximal %d Spannungswerte eingeben, Ende mit negativem Wert:\n", MAX);
	for (i=0; i<MAX; i++);
	{
		scanf("%lf", daten[i]);
		if (daten[i] < 0)
			break;
		summe += daten[i];
		anzahl++;
	}

	if (anzahl = 0)
		printf("keine Werte!\n");
		return 0;

	mittelwert = summe / anzahl;
	printf("Mittelwert: %ld V\n", mittelwert);

	return 0;
}
