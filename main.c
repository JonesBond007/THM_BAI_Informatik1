/*
	Project:	A82_Fibonacci_Folge
	File:		main.c
	Author:		Jonas Fiegert
	Date:		2023-12-13
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*---Funktionsdeklarationen----*/
int fibonacci(int n);

/*----Hauptprogramm----*/
int main() {
	int i, n;
	printf("Zahl eingeben:\n");
	scanf("%d", &n);
	printf("Die ersten %d Werte der Fibonacci-Folge sind:\n", n);

	for (i = 0; i < n; i++) {
		printf("%d\n", fibonacci(i));
	}

	return 0;
}

int fibonacci(int n) {
	if (n <= 1)
		return n;

	return fibonacci(n - 1) + fibonacci(n - 2);
}