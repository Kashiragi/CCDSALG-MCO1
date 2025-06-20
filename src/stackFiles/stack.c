#include "stack.h"

bool screate(int_sp *stack) { return (*stack = calloc(1, sizeof(struct _INTSTACKT))) != NULL; }

bool sfull(int_sp stack) { return MAX_STACK == stack->_DO_NOT_MODIFY_COUNT; }

bool sempty(int_sp stack) { return 0 == stack->_DO_NOT_MODIFY_COUNT && NULL == stack->next; }

stackerr_t spush(int_sp *pstack, int value)
{
	// Declarations
	int_sp stack, u;
	// Check if pointer is valid
	if (pstack != NULL && *pstack != NULL)
	{
		// Para di nakakalito
		stack = *pstack;
		// If empty, just change head value
		if (sempty(stack))
		{
			assert(stack->value = malloc(sizeof(int)));
			*stack->value = value;
			stack->_DO_NOT_MODIFY_COUNT++;
		}
		// If not empty, allocate a new head and attach current head
		else if (!sfull(stack))
		{
			screate(&u);
			assert(u->value = malloc(sizeof(int)));
			*u->value = value;
			u->_DO_NOT_MODIFY_COUNT = stack->_DO_NOT_MODIFY_COUNT + 1;
			u->next = stack;
			*pstack = u;
		}
		else return STACK_FULL; // Stack must be full then
	}
	else return STACK_ERROR;
	return 1;
}

stackerr_t spop(int_sp *pstack, int *out)
{
	// Declarations
	int_sp temp, stack;
	// Check if pointer is valid
	if (pstack != NULL && *pstack != NULL)
	{
		stack = *pstack;
		if (!sempty(stack))
		{
			// Check if the head is the only node of the stack
			// If so, simply remove the value of the head
			if (1 == stack->_DO_NOT_MODIFY_COUNT)
			{
				*out = *stack->value;
				free(stack->value);
				stack->_DO_NOT_MODIFY_COUNT--;
				stack->next = NULL;
			}
			// Otherwise, free the head and move the succeeding head to the front
			else
			{
				temp = stack->next;
				*out = *stack->value;
				free(stack->value);
				free(stack);
				*pstack = temp;
			}
		}
		else return STACK_EMPTY; // Stack is empty
	}
	else return STACK_ERROR; // Stack passed is invalid or corrupted
	return 1;
}

stackerr_t sfirst(int_sp stack, int *out)
{
	if (stack != NULL && out != NULL)
		if (!sempty(stack))
			*out = *stack->value;
		else return STACK_EMPTY;
	else return STACK_ERROR;
	return 1;
}

stackerr_t ssecond(int_sp stack, int *out)
{
	if (stack != NULL && out != NULL)
		if (!sempty(stack))
			if (stack->next != NULL)
				*out = *stack->next->value;
			else return STACK_NOSECOND;
		else return STACK_EMPTY;
	else return STACK_ERROR;
	return 1;
}

stackerr_t sdestroy(int_sp *pstack)
{
	int pop;
	stackerr_t result;
	result = pstack != NULL && *pstack != NULL;
	if (result)
	{
		// Pop until end is reached
		while (spop(pstack, &pop) == 1);
		// Check if all nodes are popped
		if ((result = sempty(*pstack)))
			// If stack is empty, then it can be set free accordingly
			free(*pstack), *pstack = NULL, pstack = NULL, result = 1;
		else
			// Otherwise, just return STACK_ERROR since the stack must have 
			// been interfered with an outside function causing it to not work as intended
			result = STACK_ERROR;
	}
	else; // Stack is already destroyed

	// 0 if stack is already destroyed, STACK_ERROR if stack is hijacked, 1 if successful
	return result;
}
