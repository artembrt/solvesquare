/* solvesquare.h -- constants and functions declaration */
#define COLOR_RED	"\x1b[31m"
#define COLOR_GREEN	"\x1b[32m"
#define COLOR_RESET	"\x1b[0m"

#ifndef PRECISION
	#define PRECISION 0.000001;
#endif

enum {
	ZERO,
	ONE,
	TWO,
	INF_ROOTS,
};

//square equations solving
int SolveSquare (double a, double b, double c,
		double* x1, double* x2);

//linear equation solving
int SolveLinear (double b, double c,
		double* x1, double* x2);
//
//checks double with zero
int isZero (double x);

// printing output with roots
void OutputPrinter (int nRoots, double* x1, double* x2);

