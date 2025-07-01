#include "graham_slow.h"

// Test this Graham scan algorithm with a random set of points using rpt
// NOTE: 
//    rpt uses <immintrin.h>.
//    make sure to compile in gcc with parameter -mrdrnd
// example with -Wall:
//    gcc -mrdrnd -Wall <linked set of c files>
int main()
{
	int i, result_count;
	//Point rgp[9] = {{5,5},{10,2.5},{5,10},{10,0},{7.5,0},{5,0},{0,0},{1,8},{0,10}};
	Point *rgp = NULL, *result = NULL;

	// pow(2, n) == 2 << (n - 1)
	for (i = (2 << 5); i <= (2 << 14); i <<= 1)
	{
		rpt(&rgp, 4000, i);
		slow_graham_scan(rgp, i, &result, &result_count);
	}

	free(result);
	free(rgp);
}
