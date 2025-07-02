#include "graham_slow.c"

int main()
{
    // declarations
    char inFilename[256], outFilename[256];
    int sampleSize, hullSize, i=0;
    Point inPoint, temp_point;
    Point inPointStk[32768], *arrHullPts;
    FILE *inFile, *outFile;

    printf("GRAHAM SCAN - Slow Version\n");
    // file handling, to avoid other programs open
    printf("Give me CORRECT filename for input (ex. input1.txt): ");
    scanf("%s", inFilename);
    printf("Give me CORRECT filename for output(ex. output1.txt): ");
    scanf("%s", outFilename);
    
    // Input points
    inFile = fopen(inFilename, "r");
    fscanf(inFile, "%d", &sampleSize);
    while(i<sampleSize && fscanf(inFile, "%lf %lf", &inPoint.x, &inPoint.y)==2){
        inPointStk[i] = inPoint;
        i++;
    }
    for(i=0;i<sampleSize;i++)
        printf("%lf %lf", inPointStk[i].x, inPointStk[i].y);
    fclose(inFile);
    
    //code for graham scan, incorporating sort and stack funcs
    printf("Slow graham scan in progress...\n");

    // if you can, after graham, free inPointStk, then alloc space for arrHullPts kasi 32768 elements
    // otherwise, just declare 32768 for them both sa taas na agad tysm
    slow_graham_scan(inPointStk, sampleSize, &arrHullPts, &hullSize);

    // Output hull points
    for(i=0;i<sampleSize;i++)
        printf("%lf %lf", arrHullPts[i].x, arrHullPts[i].y);
    outFile = fopen(outFilename, "w");
    fprintf(outFile, "*Number of Points: %d\n", hullSize);
    while(i<hullSize && fprintf(outFile, "%.6lf %.6lf", arrHullPts[i].x, arrHullPts[i].y)==2){ i++; }

    fclose(outFile);
    return 0;
}
