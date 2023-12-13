/*2023-11-29*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

int main(){
	int zahl, k;
	int ziffern[20];
	zahl = 0;
	printf("Umrechnung dezimal zu dual:\n");
	printf("Zahl eingeben:\n");
	scanf("%d", &zahl);

	for (k = 0; k < 20; k++) {
		ziffern[k] = zahl % 2;
		zahl = zahl / 2;
		if (zahl == 0) {
			break;
		}
	}

	printf("ergibt dual:\n");

	do {
		printf("%d", ziffern[k]);
		k = k - 1;
	} while (k >= 0);

	return 0;
}
