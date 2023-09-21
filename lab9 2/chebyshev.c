// #include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void SamplePoly(const int N,
				const int NumPts ,
				const double b[],
				const double x[],
				double y[]) {
	for (int i=0; i < NumPts; i++)
	{
		const double a = x[i]; double phi; y[i] = b[0];
		for (int k=1; k <= N; k++)
		{
			switch (k)
			{
				case 1:
					phi = a; break;
				case 2:
					phi = (2*pow(a,2)) -1; break;
				case 3:
					phi = (4*pow(a,3)) - (3*a); break;
					// 8x7 - 8x2 +1. 16x5- 20x° +5x.
				case 4:
					phi = (8*pow(a,4)) - (8*pow(a,2)) + 1; break;
				case 5:
					phi = (16*pow(a,5)) - (20*pow(a,3)) + (5*a); break;
				default :
					printf ("\n Error \n."); exit(1);
			}
			y[i] += b[k]* phi;
		}
	}
}

void WritePoly( const int NumPts ,
				const double x[],
				double y[]) {
	FILE* file = fopen("poly.data", "w");
    if(file != NULL) {
		for(int i = 0; i < NumPts; i++) {
			printf("%f %f\n", x[i], y[i]);
			fprintf(file, "%f %f\n", x[i], y[i]);
		}
		fclose(file);
    }
}

int main () {
	const int Nmax = 5;
	int N;
	// read-in polynomial degree
	printf("\n Input polynomial degree (0-%i): ", Nmax);
	scanf("%i", &N);
	if (N <0 || N>Nmax) {
		printf ("Invalid value N = %i.\n",N);
		printf ("N must satisfy: 0 <= N <= %i\n\n",Nmax);
		exit(1);
	}
	printf ("\n");

	// read-in coefficients
	double b[Nmax+1];
	for (int i=0; i <= N; i++) {
		printf ("Set b[%i]: ", i);
		scanf ("%lf", &b[i]);
	}
	printf ("\n");
	// set x- coordinates
	const int NumPts = 21;
	double x[ NumPts ];
	for (int i=0; i< NumPts; i++) {
		x[i] = -1.0 + i *(2.0/(1.0*( NumPts -1)));
	}

	// Calculate polynomial at x- coordinates
	double y[ NumPts ];
	void SamplePoly(const int N,
					const int NumPts ,
					const double b[],
					const double x[],
					double y[]);
	SamplePoly(N,NumPts ,b,x,y);
	// Write to file
	void WritePoly( const int NumPts ,
					const double x[],
					double y[]);
	WritePoly(NumPts ,x,y);

	// Call python script to plot
	system("python3 PlotPoly.py");
	return 0;
}
