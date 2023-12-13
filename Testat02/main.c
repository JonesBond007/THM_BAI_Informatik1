/*
	Name:
	Datum:				13.12.2023
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	double x, N;

	printf("x und N eingeben\n");
	scanf("%lf", &x);
	scanf("%lf", &N);

	if (x <= 0) {
		printf("x muss > 0 sein!\n");
		//return 0;
	}
	else {
		double y = x / 2;
		int k;
		for (k = 0; k < N; k++) {
			if (y * y == x) {
				break;
			}
			y = (x / y + y) / 2;
		}
		printf("Das Ergebnis ist: %.5lf\n", y);
	}

	return 0;
}