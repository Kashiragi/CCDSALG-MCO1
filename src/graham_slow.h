/**
 * graham_scan1.h contains the functions for creating the convex hull using Graham Scan, Slow version
 * 
 * @author Laguerta, Kurt Anjo
*/
#include "stack.h"
#include "sort.h"

Point anchor;

/**
 * Checks if the orientation of the three points is left (or counter-clockwise)
 * 
 * @param p1 first point
 * @param p2 the vertex of the angle orientation being checked
 * @param p2 third point, influencing the orientation (in graham scan context)
 * 
 * @return true if counter-clockwise, otherwise, false
 */
bool isccw(Point p1, Point p2, Point p3);

/**
 * Determines the convex hull from a set of given points using the graham scan. Sorting algorithm used for the slow version is 
 * selection sort.
 * 
 * @param arrptPoints array of points
 * @param nSize number of points in the array
 * @param arrConvexhull address to allocate and store the array of convex hull points
 * @param nCHSize the number of points making up the convex hull
 */
void slow_graham_scan(Point arrptPoints[], int nSize, Point **arrConvexHull, int *nCHSize);
