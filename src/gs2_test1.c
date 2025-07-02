#include "graham_fast.h"

// Test this Graham scan algorithm with a random set of points using rpt
// NOTE: 
//    rpt uses <immintrin.h>.
//    make sure to compile in gcc with parameter -mrdrnd
// example with -Wall:
//    gcc -mrdrnd -Wall <linked set of c files>
int main()
{
	int i, result_count;
	int nSize = 9;
	Point points[] = {
		{5.0, 5.0},
		{10.0, 2.5},
		{5.0, 10.0},
		{10.0, 0.0},
		{7.5, 0.0},
		{5.0, 0.0},
		{0.0, 0.0},
		{1.0, 8.0},
		{0.0, 10.0}
	};
	Point *result;

	printf("Points are...\n");
	for (i = 0; i < nSize; i++)
		printf("%.2lf;%.2lf\n", points[i].x, points[i].y);
	printf("\n");

	graham_scan_fast(points, nSize, &result, &result_count);

	printf("Convex hull points are...\n");
	for (i = 0; i < result_count; i++)
		printf("%.2lf;%.2lf\n", result[i].x, result[i].y);
	printf("\n");

}
