#include "rpt.h"

void rpt(Point *rGenAlloc[], int nNumberRange, int nDesiredSize)
{
	int i, ex;
	unsigned long long w, t;
	double f;
	
	// Random x and y values are obtained as follows:
	// - obtain whole part by a random unsigned long long modulo desired dimension
	// - obtain fractional part only by multiplying exponent of opposite sign
	//   then getting floating modulo by 1
	assert(*rGenAlloc = malloc(nDesiredSize * sizeof(Point)));
	for (i = 0; i < nDesiredSize; i++)
	{
		// x-coordinate
		_rdrand64_step(&w);
		_rdrand64_step((unsigned long long *)(&f));
		ex = -(int)(floor(log10(fabs(f))));
		f = fabs(fmod(f * pow(10, ex), 1.0));
		if (isnan(f))
			_rdrand64_step(&t), f = fmod(sqrt(t + 1.0), 1.0); else;
		(*rGenAlloc)[i].x = (w % nNumberRange) + f;
		
		// y-coordinate
		_rdrand64_step(&w);
		_rdrand64_step((unsigned long long *)(&f));
		ex = -(int)(floor(log10(fabs(f))));
		f = fabs(fmod(f * pow(10, ex), 1.0));
		if (isnan(f))
			_rdrand64_step(&t), f = fmod(sqrt(t + 1.0), 1.0); else;
		(*rGenAlloc)[i].y = (w % nNumberRange) + f;
	}
}
