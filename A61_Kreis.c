/*
	Project:	A61_Kreis
	File:		main.c
	Author:		JonesBond007
	Date:		2023-11-29
*/

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include "simple_draw.h"
#include <math.h>
#include <stdlib.h>

int main(){
	double radius;
	double x, y, xm, ym, a;
	int red, green, blue, width;
	x = y = 0;
	xm = 350;
	ym = 250;

	printf("Radius eingeben:\n");
	scanf("%lf", &radius);
	printf("Rot-, Gruen- und Blauanteil eingeben:\n");
	scanf("%d %d %d", &red, &green, &blue);
	printf("Linienstaerke eingeben:\n");
	scanf("%d", &width);

	ClearGraphic();
	MoveTo(xm+radius, ym);
	SetPen(red, green, blue, width);

	for (int i = 0; i <= 360; i++) {
		a = i * M_PI / 180;
		x = xm + radius * cos(a);
		y = ym - radius * sin(a);
		DrawTo(x, y);
	}

	return 0;
}
