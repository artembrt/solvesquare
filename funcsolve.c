#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "solvesquare.h"

int SolveSquare (double a, double b, double c,
		double* x1, double* x2)
	{
	assert (isfinite (a));
	assert (isfinite (b));
	assert (isfinite (c));

	assert (x1 != NULL);
	assert (x2 != NULL);
	assert (x1 != x2);

	if (isZero(a))
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
	assert (isfinite (b));
	assert (isfinite (c));

	assert (x1 != NULL);
	assert (x2 != NULL);
	assert (x1 != x2);

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
	assert (isfinite (x));
	return  fabs(x) < PRECISION;
	}
