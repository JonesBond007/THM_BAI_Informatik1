/*
	Project:	A71_Mandelbrot
	File:		main.c
	Author:		Jonas Fiegert
	Date:		2023-12-05
*/

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include "simple_draw.h"
#include <stdlib.h>
#include <math.h>

int countLoops(double Re, double Im); //Deklaration der Funktion countLoops

int main()
{
	double Re_0, Im_0, zoom;

	//Parameter eingeben
	printf("Realteil eingeben:\n");
	scanf("%lf", &Re_0);
	printf("Imaginaerteil eingeben:\n");
	scanf("%lf", &Im_0);
	printf("Vergroesserung eingeben:\n");
	scanf("%lf", &zoom);
	
	ClearGraphic();

	for (int y = 0; y < 500; y++) {
		for (int x = 0; x < 700; x++) {
			double Re = Re_0 + (x - 350) / (zoom * 200);
			double Im = Im_0 - (y - 250) / (zoom * 200);

			int n = countLoops(Re, Im); //Methodenaufruf

			double b = sqrt(n);
			DrawPixel(x, y, b * 25.6, b * 25.6, 250 - (b * 25));
		}
	}

	return 0;
}

int countLoops(double Re, double Im) { //Definition der Methode
	double Z_re, Z_im;
	Z_re = Z_im = 0;
	int n;

	for (n = 0; n < 100; n++) {
		double Z_im_new = 2 * Z_re * Z_im + Im;
		Z_re = Z_re * Z_re - Z_im * Z_im + Re;
		Z_im = Z_im_new;

		if (Z_re * Z_re + Z_im * Z_im > 9) {
			return n;
		}
	}
}