#include "..\sortFiles\sort.h"
#include "..\stackFiles\stack.h"
#include <time.h>
#include <stdio.h>

Point anchor;

/**
 * Check the orientation if the next point turn left (counter-clockwise), right (clockwise),
 * or not at all (collinear).
 * 
 * @param previous the previous point
 * @param current the pivot point; where the angle is pivoted on
 * @param next the next point being check if it should be added to the hull or not
*/
int checkCCW(Point previous, Point current, Point next);

void graham_scan_fast(Point points[], int sampleSize, Point **hull, int *hullSize);