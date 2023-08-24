#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "solvesquare.h"

int main()
	{
	printf("\033[1;31mThis is bold red text\033[0m\n");
	printf ("\033[1;31mSquare equation solver\033[0m\n");
	printf ("Enter a,b,c\n");

	double x1 = 0, x2 = 0;
	const double a = 0, b = 0, c = 0;
	
	scanf("%lg%lg%lg", &a, &b, &c);

	int nRoots = SolveSquare (a, b, c, &x1, &x2);

	OutputPrinter(nRoots, &x1, &x2);

	}

void OutputPrinter (int nRoots, double* x1, double* x2)
	{
	switch (nRoots)
		{
		case ZERO: printf (COLOR_GREEN "No roots\n" COLOR_RESET);
			break;

		case ONE: printf ("One root %lg\n", *x1);
			break;

		case TWO: printf ("Two roots x1 = %lg, x2 = %lg\n", *x1, *x2);
			break;

		case INF_ROOTS: printf ("Any root\n");
			break;

		default: printf (COLOR_RED "ERROR\n" COLOR_RESET);
			break;

		}
	}
