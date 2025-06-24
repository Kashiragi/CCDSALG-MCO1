#include "stack.h"

void trycreate(point_sp *stack) { printf("cr %d\n", screate(stack)); }
void trydestroy(point_sp *stack) { printf("dest %d\n", sdestroy(stack)); }
void trypop(point_sp *stack)
{
	stackerr_t result;
	Point pop;
	result = spop(stack, &pop);
	printf("pop (%.2lf,%.2lf) 0x%X\n", pop.x, pop.y, result);
}
void trypush(point_sp *stack, Point value) { printf("push (%.2lf,%.2lf) 0x%X\n", value.x, value.y, spush(stack, value)); }
void tryfs(point_sp stack)
{
	stackerr_t result;
	Point *value;
	printf("fs ");
	((result = sfirst(stack, &value)) == 1)
		? printf("(%.2lf,%.2lf) ", value->x, value->y)
		: printf("0x%uX ", result);
	((result = ssecond(stack, &value)) == 1)
		? printf("(%.2lf,%.2lf)", value->x, value->y)
		: printf("0x%X ", result);
	printf("\n");
}
void tryprint(point_sp stack)
{
	point_sp u;
	printf("prn ");
	if (NULL == stack)
		printf("0");
	else
		for (u = stack; u != NULL; u = u->next)
			printf("(%.2lf,%.2lf) ", u->value->x, u->value->y);
	printf("\n");
}

int main()
{
	point_sp stack;
	trycreate(&stack);
	trypop(&stack);
	trypush(&stack, (Point) { 2.01, 4.03 });
	trypush(&stack, (Point) { 1.86, 2.71 });
	tryfs(stack);
	trypop(&stack);
	trypush(&stack, (Point) { 3.00, 2.90 });
	trypush(&stack, (Point) { 5.91, 10.657 });
	trypush(&stack, (Point) { 12.06, 9.59 });
	tryprint(stack);
	trypop(&stack);
	tryfs(stack);
	tryprint(stack);
	trypop(&stack);
	tryfs(stack);
	tryprint(stack);
	trydestroy(&stack);
	trypop(&stack);
	trypush(&stack, (Point) { 9.65, 22.22 });
	tryfs(stack);
	tryprint(stack);
}
