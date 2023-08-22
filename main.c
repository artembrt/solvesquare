#include <stdio.h>
#include <math.h>

double PRECISION = 0.000001;

enum {
	ZERO,
	ONE,
	TWO,
	INF_ROOTS,
};

int main()
	{
	printf ("Square equation solver\n");
	printf ("Enter a,b,c\n");

	double x1 = 0, x2 = 0;
	const double a = 0, b = 0, c = 0;

	scanf("%lg%lg%lg", &a, &b, &c);

	int nRoots = SolveSquare (a, b, c, &x1, &x2);

	switch (nRoots)
		{
		case ZERO: printf ("No roots\n");
			break;

		case ONE: printf ("One root %lg\n", x1);
			break;

		case TWO: printf ("Two roots x1 = %lg, x2 = %lg\n", x1, x2);
			break;

		case INF_ROOTS: printf ("Any root\n");
			break;
		
		default: printf ("ERROR\n");
			break;

		}
	}

int SolveSquare (double a, double b, double c,
		double* x1, double* x2)
	{

		if (a == 0)
			{
			int nRoots = SolveLinear (b, c, &x1, &x2);
			return nRoots;
			}
		else /* if (a != 0) */
			{
			double d = b * b - 4 * a * c;

			if (isZero(d))
				{
				*x1 = *x2 = -b / (2 * a);
				return ONE;
				}
			else if (d < 0)
				{
				return ZERO;
				}
			else 
				{
				*x1 = (-b + sqrt(d)) / 2 / a;
				*x2 = (-b - sqrt(d)) / 2 / a;
				return TWO;
				}
			}
	}


int SolveLinear (double b, double c,
		double* x1, double* x2)
	{
			if (isZero(b))
				{
				return INF_ROOTS;
				}
			else /* if b != 0*/
				{
				*x1 = *x2 = -c / b;
				return ONE;
				}
	}

int isZero (double x)
	{
		return if ( fabs(x) < PRECISION);
	}
