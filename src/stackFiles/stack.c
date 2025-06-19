#include "stack.h"

// Creates a new stack instance
void screate(int_sp *stack) { *stack = calloc(1, sizeof(struct _INTSTACKT)); }

// Checks if full
bool sfull(int_sp stack) { return MAX_STACK == stack->_DO_NOT_MODIFY_COUNT; }

// Checks if empty
bool sempty(int_sp stack) { return 0 == stack->_DO_NOT_MODIFY_COUNT && NULL == stack->next; }

stackerr_t spush(int_sp *pstack, int value)
{
	// Declarations
	int_sp stack, u;
	stackerr_t result;
	// Check if pointer is valid
	result = pstack != NULL && *pstack != NULL;
	if (result)
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
		else
			result = STACK_FULL; // Stack must be full then
	}
	else
		result = STACK_ERROR; // Something's wrong with the parameter
	return result;
}

stackerr_t spop(int_sp *pstack, int *out)
{
	// Declarations
	int_sp pTemp, stack;
	stackerr_t result;
	// Check if pointer is valid
	result = pstack != NULL && *pstack != NULL;
	if (result)
	{
		// Para di nakakalito
		stack = *pstack;
		// Check if empty
		result = !sempty(stack);
		if (result)
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
			else
			{
				pTemp = stack->next;
				*out = *stack->value;
				free(stack->value);
				free(stack);
				*pstack = pTemp;
			}
		}
		else
			result = STACK_EMPTY; // Stack must be empty then
	}
	else
		result = STACK_ERROR; // Something's wrong with the parameter
	return result;
}

// Returns top value if successful, otherwise returns STACK_ERROR
int sfirst(int_sp stack) { return stack != NULL && stack->value != NULL ? *stack->value : STACK_ERROR; }

// Returns second value from the top if successful, otherwise returns STACK_ERROR
int ssecond(int_sp stack) { return stack != NULL && stack->next != NULL ? *stack->next->value : STACK_ERROR; }

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
