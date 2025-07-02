#include "graham_fast.h"

int checkCCW(Point previous, Point current, Point next){
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

void graham_scan_fast(Point points[], int sampleSize, Point **hull, int *hullSize){
    //declarations
    int i;
    point_sp workStk;
    //timer related
    clock_t startTm, endTm;

    startTm = clock();
    
    // step by step implementation using these key steps
    // https://www.numberanalytics.com/blog/mastering-grahams-scan-algorithm

    // determine anchor point using search
    for (i = 1, anchor = points[0]; i < sampleSize; i++)
    if ((points[i].y < anchor.y) || (points[i].y == anchor.y && points[i].x < anchor.x))
    anchor = points[i];
    
    // merge sort the array based on polar angles
    mergeSort(points,sampleSize);
    
    // initialize working stack
    screate(&workStk);
    
    i = 0;
    Point *p = NULL, *c=NULL, dump= (Point){0,0};
    while(i<sampleSize){
        // check if not empty
        // check if first exists
        // check if second or next to top exists
        // check if collinear or clockwise. will continuously remove all collinear
        while(!sempty(workStk) && sfirst(workStk,&c)!=STACK_EMPTY && ssecond(workStk,&p)!=STACK_NOSECOND && checkCCW(*p,*c,points[i])<=0){
            spop(&workStk, &dump);
        }
        spush(&workStk, points[i]);
        i++;
        //    pseudo/old code
        //    while i!=sampleSize
        //    
        //    p = next to top
        //   c = top
        //    n = point[i]
        //    
        //    orie = orientation(p,c,n)
        // if(i<3 || checkCCW(*p, *c, points[i])==1){
        //     spush(&workStk, points[i]);
        //     i++;
        // }
        // else if (i>=3 && checkCCW(*p,*c,points[i])==0){
        //     spop(&workStk, &dump);
        //     spush(&workStk, points[i]);
        //     i++;
        // }
        // else if (i>=3 &&checkCCW(*p,*c,points[i])==-1){
            //     spop(&workStk, &dump);
            // }
        //   
            //   if +1, push(n), i++
            //    else if 0, pop(top), push(n), i++
            //    else if -1, pop(top)

    }
    
    // reverse working stack into final stack (sicne ang output ay anchor first)
    // return final stack
    sarray(&workStk, hull);
    *hullSize = workStk->_DO_NOT_MODIFY_COUNT;

    sdestroy(&workStk);

    endTm = clock();
    printf("%6d %15lf\n", sampleSize, (double)(endTm - startTm)); 
}