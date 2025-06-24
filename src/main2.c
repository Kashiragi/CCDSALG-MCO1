#include "globals.h"
#include "stackFiles/stack.h"
#include "sortFiles/sort.h"
//#include "graham_scan2.c" ->> the actual include. stack and sort temporarily
//Main module for the fast version

int main(){

    FILE *inFile, *outFile;
    int sampleSize, hullSize;
    Point inPoint;
    int_sp inPointStk, hullStack;

    screate(inPointStk);

    inFile = fopen("sample-input.txt", "r");
    fscanf(inFile, "%d", &sampleSize);
    while(fscanf(inFile, "%lf %lf", &inPoint.x, &inPoint.y)==2){
        spush(inPointStk, inPoint);
    }
    fclose(inFile);

    //code for graham scan, incorporating sort and stack funcs
    /**
     * GRAHAM FUNCTION NOTES:
     *      inside graham function, anchor gets pushed first then check cehck cehck until last point
     *      Afterwards, flip the stack on its head (reverse) then return for use in main
     * 
     *      Additionally, graham scan must have parameter of a stack. The stack contains the points to be used, and sorted
     */

    /**
     * THE IDEA HERE:
     *      graham_scan will have a function that returns the hull na tama, where the bottom is the anchor (first to be printed and popped)
     *      tas nasa top ung last point. The while loop will continue until mapop lahat.
     */
    outFile = fopen("SAMPLE OUTPUT 1.txt", "w");
    fprint(outFile, "*Number of Points: %d\n", hullSize);
    while(!sempty(hullStack)){
        fprintf(outFile, "%.6lf %.6lf", hullStack->value);
        spop(hullStack, (*hullStack).value);
    }
    fclose(outFile);
    return 0;
}
