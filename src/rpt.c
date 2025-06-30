#include "rpt.h"

void rpt(Point *rGenAlloc[], int nSquareDimension, int nDesiredCount)
{
	int i, ex;
	unsigned long long w;
	double f;
	
	// Random x and y values are obtained as follows:
	// - obtain whole part by a random unsigned long long modulo desired dimension
	// - obtain fractional part only by multiplying exponent of opposite sign
	//   then getting floating modulo by 1
	assert(*rGenAlloc = malloc(nDesiredCount * sizeof(Point)));
	for (i = 0; i < nDesiredCount; i++)
	{	
		// x-coordinate
		_rdrand64_step(&w);
		_rdrand64_step((unsigned long long *)(&f));
		ex = floor(log10(fabs(f)));
		ex = ex != 0 ? -ex : 0;
		f = fabs(fmod(f * pow(10, ex), 1.0));
		(*rGenAlloc)[i].x = (w % nSquareDimension) + f;
		
		// y-coordinate
		_rdrand64_step(&w);
		_rdrand64_step((unsigned long long *)(&f));
		ex = floor(log10(fabs(f)));
		ex = ex != 0 ? -ex : 0;
		f = fabs(fmod(f * pow(10, ex), 1.0));
		(*rGenAlloc)[i].y = (w % nSquareDimension) + f;
	}
}
