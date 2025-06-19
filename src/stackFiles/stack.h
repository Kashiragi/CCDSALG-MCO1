#include "stdlib.h"
#include "assert.h"
#include "stdbool.h"

// Max stack is 2^15 = 32768
#define MAX_STACK 1<<15

// Error codes
#define STACK_ERROR -0x57ACC077 // "STAC(K) CORR(upted)". Stack is invalid or not working as intended
#define STACK_FULL  -0X57ACFFFF // "STAC(K) FFFF". Stack has reached its upper limit
#define STACK_EMPTY -0x57AC0000 // "STAC(K) 0x0000". Stack has 0x0000 elements

typedef struct _INTSTACKT
{
	int _DO_NOT_MODIFY_COUNT;
	int *value;
	struct _INTSTACKT *next;
} *int_sp;

typedef int stackerr_t;

void screate(int_sp *stack);
bool sfull(int_sp stack);
bool sempty(int_sp stack);
stackerr_t spush(int_sp *pstack, int value);
stackerr_t spop(int_sp *pstack, int *out);
int sfirst(int_sp stack);
int ssecond(int_sp stack);
stackerr_t sdestroy(int_sp *pstack);