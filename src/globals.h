#ifndef GLOBALS_H 
//used since globals is declared in two separate files that will be used by OTHER files
//to avoid double inclusion
#define GLOBALS_H

//stack related
typedef struct _INTSTACKT
{
	int _DO_NOT_MODIFY_COUNT;
	int *value;
	struct _INTSTACKT *next;
} *int_sp;

typedef int stackerr_t;

//sort related
typedef struct {
    double x;
    double y;
} Point;

extern Point anchor;

#endif