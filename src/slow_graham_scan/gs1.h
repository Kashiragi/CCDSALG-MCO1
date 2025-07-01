#include "../stackFiles/stack.h"
#include "../sortFiles/sort.h"
#include "../random_point_generator/rpt.h"

#define RPT_SIZE 16

Point anchor;

/// <summary>
/// Checks if the orientation of three given points is counterclockwise.
/// </summary>
/// <param name="p1">- Point 1.</param>
/// <param name="p2">- Point 2.</param>
/// <param name="p3">- Point 3.</param>
/// <returns>True or false accordingly.</returns>
bool isccw(Point p1, Point p2, Point p3);

/// <summary>
/// Determines the convex hull points from a set of given points.
/// The sorting algorithm used for this function is selection sort.
/// </summary>
/// <param name="arrptPoints">- Given array of points.</param>
/// <param name="nSize">- Number of points within the array.</param>
/// <param name="arrConvexHull">- Address to allocate and store the array of convex hull points.</param>
/// <param name="nCHSize">- Output variable to store the number of points making up the convex hull.</param>
void slow_graham_scan(Point arrptPoints[], int nSize, Point **arrConvexHull, int *nCHSize);
