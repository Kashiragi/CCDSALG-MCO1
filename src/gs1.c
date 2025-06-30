#include "stackFiles/stack.h"
#include "sortFiles/sort.h"
#include "rpt.h"

#define RGP_SIZE 10

Point anchor;

bool isccw(Point p1, Point p2, Point p3) { return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x) > 0.0; }

point_sp slow_graham_scan(Point arrptPoints[], int nSize)
{
	int i;
	bool flag;
	point_sp psp;
	Point *first = NULL, *second = NULL, ptdump = { 0,0 };
	if (!screate(&psp))
		fprintf(stderr, "slow_graham_scan: cannot create stack"), abort();
	
	// Find point with lowest y-value, will serve as anchor
	for (i = 0; i < nSize; i++)
		if (arrptPoints[i].y < anchor.y)
			anchor = arrptPoints[i];

	// Sort accordingly
	selectionSort(arrptPoints, nSize);

	// This loop gets the points properly sometimes, pero there are times na may kulang
	spush(&psp, arrptPoints[0]);
	spush(&psp, arrptPoints[1]);
	spush(&psp, arrptPoints[2]);
	for (i = 3; i < nSize; i++)
	{
		do
		{
			// Check preliminaries:
			// - ... if stack has contents
			// - ... if stack has a top element
			// - ... if stack has an element after the top one
			if ((flag = !sempty(psp) && sfirst(psp, &first) != STACK_EMPTY && ssecond(psp, &second) != STACK_NOSECOND))
				// Pop if clockwise or collinear (!ccw)
				if ((flag = !isccw(*second, *first, arrptPoints[i])))
					spop(&psp, &ptdump);
				else;
			else;
		} while (flag);
		spush(&psp, arrptPoints[i]);
	}
	
	return psp;
}

int main()
{
	// NOTE: make sure to compile in gcc with parameter -mrdrnd
	// Example:
	// gcc -mrdrnd -Wall <linked set of c files>

	int i;
	Point *rgp;
	Point out;
	point_sp result;
	rpt(&rgp, 100, RGP_SIZE);

	printf("Points are... \n");
	for (i = 0; i < RGP_SIZE; i++)
		printf("%.2lf;%.2lf\n", rgp[i].x, rgp[i].y);
	printf("\n");

	result = slow_graham_scan(rgp, RGP_SIZE);

	printf("Convex hull points are...\n");
	while (!sempty(result))
	{
		spop(&result, &out);
		printf("%.2lf;%.2lf\n", out.x, out.y);
	}

	assert(sdestroy(&result) == 1);
	free(rgp);
}
