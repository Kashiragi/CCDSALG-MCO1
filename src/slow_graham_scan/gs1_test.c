#include "gs1.h"

// Test this Graham scan algorithm with a random set of points using rpt
// NOTE: 
//    rpt uses <immintrin.h>.
//    make sure to compile in gcc with parameter -mrdrnd
// example with -Wall:
//    gcc -mrdrnd -Wall <linked set of c files>
int main()
{
	int i, j, result_count;
	//Point rgp[9] = {{5,5},{10,2.5},{5,10},{10,0},{7.5,0},{5,0},{0,0},{1,8},{0,10}};
	Point *rgp = NULL, *result = NULL;

	for (j = 6, i = (int)pow(2, j); i <= (int)pow(2, 15); j++, i = (int)pow(2, j))
	{
		rpt(&rgp, 4000, i);
		slow_graham_scan(rgp, i, &result, &result_count);
	}

	free(result);
	free(rgp);
}
