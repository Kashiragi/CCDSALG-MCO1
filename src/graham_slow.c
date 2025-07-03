#include "graham_slow.h"

bool isccw(Point p1, Point p2, Point p3) { return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x) > 0; }

void slow_graham_scan(Point arrptPoints[], int nSize, Point **arrConvexHull, int *nCHSize){
	// For time recording
	clock_t start, end;
	// Declarations
	int i;
	bool flag;
	point_sp psp;
	Point *first = NULL, *second = NULL, ptdump = { 0,0 };

	// Start time recording
	start = clock();

	// Create temporary stack
	assert(screate(&psp) == 1);

	// Find point with lowest y-value, will serve as anchor	
	for (i = 1, anchor = arrptPoints[0]; i < nSize; i++)
		if ((arrptPoints[i].y < anchor.y) || (arrptPoints[i].y == anchor.y && arrptPoints[i].x < anchor.x))
			anchor = arrptPoints[i];

	// Sort accordingly
	selectionSort(arrptPoints, nSize);

	// Algorithm as interpreted from Wikipedia's pseudocode
    // https://en.wikipedia.org/wiki/Graham_scan#Pseudocode
	for (i = 0; i < nSize; i++)
	{
		do
		{
			// Check preliminaries:
			// - ... if stack has contents
			// - ... if stack has a top element
			// - ... if stack has an element after the top one
			// Pop if clockwise or collinear (!ccw)
			if ((flag = !sempty(psp) && sfirst(psp, &first) != STACK_EMPTY &&
				ssecond(psp, &second) != STACK_NOSECOND && !isccw(*second, *first, arrptPoints[i])))
				assert(spop(&psp, &ptdump) == 1);
		} while (flag);
		assert(spush(&psp, arrptPoints[i]) == 1);
	}
	
	// Create an array from the temporary stack and then destroy the stack
	assert((*nCHSize = sarray(&psp, arrConvexHull)) == psp->_DO_NOT_MODIFY_COUNT);
	assert(sdestroy(&psp) == 1);

	// Finish time recording
	end = clock();
	printf("Slow Graham scan finished. Took %lf ms over %d points\n", (double)(end - start)/CLOCKS_PER_SEC * 1000.0, nSize);
}
