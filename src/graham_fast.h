/**
 * graham_scan2.h contains the functions for creating the convex hull using Graham Scan, Fast version.
 * 
 * @author Saguin, VL Kirsten Camille
*/
#include "sort.h"
#include "stack.h"

Point anchor;

/**
 * Check the orientation if the next point turn left (counter-clockwise), right (clockwise),
 * or not at all (collinear).
 * 
 * @param previous the previous point
 * @param current the pivot point; where the angle is pivoted on
 * @param next the next point being check if it should be added to the hull or not
 * 
 * @return 1 if counter-clockwise, -1 if clockwise, 0 if collinear
*/
int checkCCW(Point previous, Point current, Point next);

/**
 * Determines the convex hull from a set of given points using the graham scan. Sorting algorithm used for the slow version is 
 * selection sort.
 * 
 * @param points array of points
 * @param sampleSize number of points in the array
 * @param hull address to allocate and store the array of convex hull points
 * @param hullSize the number of points making up the convex hull
 */
void graham_scan_fast(Point points[], int sampleSize, Point **hull, int *hullSize);