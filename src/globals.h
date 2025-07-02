#ifndef GLOBALS_H 
//used since globals is declared in two separate files that will be used by OTHER files
//to avoid double inclusion
#define GLOBALS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <time.h>

// Max stack is 2^15 = 32768.
#define MAX_STACK (1<<15)

// Error codes

// "OVER(load)". Stack has reached its upper limit.
#define STACK_FULL -0x05E7
// "ZERO". Stack has zero nodes.
#define STACK_EMPTY -0x2E70
// "SOLO". Exclusively for ssecond(). 
// There is only one node in the stack and no second node to seek.
#define STACK_NOSECOND -0x5010
// "CORR(upted)". Stack is invalid or not working as intended.
#define STACK_ERROR -0xC077

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502884L
#endif

//sort related
typedef struct {
	double x;
	double y;
} Point;

//stack related
typedef struct _INTSTACKT
{
	int _DO_NOT_MODIFY_COUNT;
	Point *value;
	struct _INTSTACKT *next;
} *point_sp;

typedef int stackerr_t;

extern Point anchor;

#endif
