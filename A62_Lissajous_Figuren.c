/*
	Project:	A62_Lissajous_Figuren
	File:		main.c
	Author:		JonesBond007
	Date:		2023-12-04
*/

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include "simple_draw.h"
#include <stdlib.h>
#include <math.h>

void drawGraphic(double n1, double n2, double w) {
	ClearGraphic();
	SetPen(255, 0, 0, 3);

	for (double t = 0; t < 2 * M_PI; t += 0.01) {
		double x = 350 + 200 * sin(n1 * t + w);
		double y = 250 + 200 * sin(n2 * t + w);
		if (t == 0) MoveTo(x, y);
		DrawTo(x, y);
	}
}

int main()
{
	double n1, n2, w;
	
	printf("n1:\n");
	scanf("%lf", &n1);
	printf("n2:\n");
	scanf("%lf", &n2);
	printf("Phasenverschiebung eingeben:\n");
	scanf("%lf", &w);

	if (w > 360) {
		for (;;) {
			if (w >= 0 && w <= 360) {
				break;
			}
			else {
				w = w - 360;
			}
		}
	}
	else if (w < 0) {
		for (;;) {
			if ( w >= 0 && w <= 360) {
				break;
			}
			else {
				w = w + 360;
			}
		}
		
	}
	
	drawGraphic(n1, n2, w);
	
	return 0;
}
