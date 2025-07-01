#include "gs1.h"

// Test this Graham scan algorithm with a random set of points using rpt
// NOTE: 
//    rpt uses <immintrin.h>.
//    make sure to compile in gcc with parameter -mrdrnd
// example with -Wall:
//    gcc -mrdrnd -Wall <linked set of c files>
int main()
{
	int i, result_count;
	Point *rgp;
	Point *result;
	rpt(&rgp, 50, RPT_SIZE);

	printf("Points are...\n");
	for (i = 0; i < RPT_SIZE; i++)
		printf("%.2lf;%.2lf\n", rgp[i].x, rgp[i].y);
	printf("\n");

	slow_graham_scan(rgp, RPT_SIZE, &result, &result_count);

	printf("Convex hull points are...\n");
	for (i = 0; i < result_count; i++)
		printf("%.2lf;%.2lf\n", result[i].x, result[i].y);
	printf("\n");

	free(result);
	free(rgp);
}
