#include "graham_fast.h"


int main() {
    char inFilename[256], outFilename[256];
    int sampleSize, hullSize;
    int i = 0;
    Point inPoint;
    Point inPointStk[32768];
    Point *arrHullPts;
    FILE *inFile, *outFile;

    printf("GRAHAM SCAN - Fast Version\n");
    printf("Give me CORRECT filename for input (ex. input1.txt): ");
    scanf("%255s", inFilename);
    printf("Give me CORRECT filename for output(ex. output1.txt): ");
    scanf("%255s", outFilename);

    inFile = fopen(inFilename, "r");
    if (!inFile) { perror("fopen input"); return 1; }
    fscanf(inFile, "%d", &sampleSize);
    while (i < sampleSize && fscanf(inFile, "%lf %lf", &inPoint.x, &inPoint.y) == 2) {
        inPointStk[i++] = inPoint;
    }
    fclose(inFile);

    printf("Fast graham scan in progress...\n");
    //sortPointsByPolarAngle(inPointStk, sampleSize, 0);
    graham_scan_fast(inPointStk, sampleSize, &arrHullPts, &hullSize);



    // DEBUG: print hull to console
    printf(">>> Hull has %d points:\n", hullSize);
    for (int j = 0; j < hullSize; j++) {
        printf("  arrHullPts[%2d] = (%.6f, %.6f)\n",
               j, arrHullPts[j].x, arrHullPts[j].y);
    }
    printf(">>> End of hull dump\n\n");

    // Write hull to output file
    outFile = fopen(outFilename, "w");
    if (!outFile) { perror("fopen output"); free(arrHullPts); return 1; }
    fprintf(outFile, "%d\n", hullSize);
    for (int k = 0; k < hullSize; k++) {
        fprintf(outFile, "%.6lf %.6lf\n",
                arrHullPts[k].x, arrHullPts[k].y);
    }
    fclose(outFile);
    free(arrHullPts);

    return 0;
}

