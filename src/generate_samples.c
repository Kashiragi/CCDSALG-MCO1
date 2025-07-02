#include "rpt.h"

// Test this Graham scan algorithm with a random set of points using rpt
// NOTE: 
//    rpt uses <immintrin.h>.
//    make sure to compile in gcc with parameter -mrdrnd
// example with -Wall:
//    gcc -mrdrnd -Wall <linked set of c files>
int main()
{
	FILE *file;
	int i, j, filename_length;
	char *strFilename;
	for (i = (1 << 6), j = 1; i <= (1 << 15); i <<= 1, j++)
	{
		filename_length = snprintf(NULL, 0, "in%d.txt", j);
		assert(strFilename = malloc(filename_length + 1));
		snprintf(strFilename, filename_length + 1, "in%d.txt", j);
		rpt_by_file(strFilename, 2000, i);
		free(strFilename);
	}
	return 0;
}
