#include "sortFiles\sort.c"
#include "stackFiles\stack.c"

//Graham's scan using fast version

/**
 * GRAHAM FUNCTION NOTES:
 *      inside graham function, anchor gets pushed first then check cehck cehck until last point
 *      Afterwards, flip the stack on its head (reverse) then return for use in main
 * 
 *      Additionally, graham scan must have parameter of a stack. The stack contains the points to be used, and sorted
 */

/** Pseudocode
 * input the array of points
 * 
 * find the first point, lowest x and y, using search algo
 * 
 * sort thru points using merge sort based on polar angle (out the empiracal time as needed)
 *  
 * initialize working stack
 * push first 3 points sa stack (p, c, n) top=n
 * now, next to top (which is c) becomes p, top becomes c, then next in the array becoms n
 * check orientation if counterclock or clockwise from c to n
 *     -> if counter, push to stack, top is now c, next point in array is n
 *     -> if clock, pop top then move to next point as n
 *     -> if collinear, pop top then add that point, since dulong dulo
 * 
 * go through the entire array til last point
 */

/**
 * Check the orientation if the next point turn left (counter-clockwise), right (clockwise),
 * or not at all (collinear).
 * 
 * @param previous the previous point
 * @param current the pivot point; where the angle is pivoted on
 * @param next the next point being check if it should be added to the hull or not
 */
int checkOrientation(Point previous, Point current, Point next){
    // Intermediate computations
    // let uxv (cross) = x1 x y2 - x2 x y1 
    // vectorCN
    // next.x - current.x, next.y - current.y; // CN
    // vector PC
    // current.x - previous.x, current.y - previous.y;//PC
    // PC x CN = = x1 x y2 - x2 x y1 
    double crossProd = (current.x - previous.x) * (next.y - current.y) - (next.x - current.x) * (current.y - previous.y);
    
    return (crossProd > 0) ? 1 : (crossProd < 0) ? -1 : 0;
}

point_sp graham_scan_slow(Point points[], int sampleSize){
    
    // determine anchor point using search

    // merge sort the array

    // initialize working stack
    // push first 3 points into stack

    // i = 2
    /**
     *  while i!=sampleSize
     *      
     *      p = next to top
     *      c = top
     *      n = point[i]
     *      
     *      orie = orientation(p,c,n)
     * 
     *      if +1, push(n), i++
     *      else if 0, pop(top), push(n), i++
     *      else if -1, pop(top)
    */
    
    // reverse working stack into final stack (sicne ang output ay anchor first)

    // return final stack
}