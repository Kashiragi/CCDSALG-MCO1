/**
 * stack.h contains the functions for creating a stack data structure using a linked list.
 * 
 * @author Laguerta, Kurt Anjo
*/
#ifndef STACK_H
#define STACK_H

#include "globals.h"
/**
 * Creates a new stack instance
 * 
 * @param stack pointer to the stack
 * @return 1 if the stack is succesfully allocated; otherwise, 0
 */
bool screate(point_sp *stack);

/**
 * Checks if the stack is full
 * 
 * @param stack the stack to check if full
 * @return 1 if stack is full; otherwise, 0
 */
bool sfull(point_sp stack);

/**
 * Checks if the stack is full
 * 
 * @param stack the stack to check if full
 * @return 1 if stack is empty; otherwise, 0
 */
bool sempty(point_sp stack);

/**
 * Pushes a value to the top of the stack
 * 
 * @param pstack pointer to the stack to have value pushed
 * @param value value to be pushed to the stack
 * 
 * @return 1 if stored successfully, STACK_FULL if stack is full, STACK_ERROR if pstack is invalid
 */
stackerr_t spush(point_sp *pstack, Point value);

/**
 * Pops the value on the top of the stack
 * 
 * @param pstack pointer to the stack to have value pushed
 * @param out where to store the value of the retrieved node
 * 
 * @return 1 if popped successfully and the retrieved value is stored into *out, STACK_EMPTY if stack is empty, STACK_ERROR if pstack is invalid
 * @note The value of *out remains unchanged if the process is unsuccessful.
 */
stackerr_t spop(point_sp *pstack, Point *out);

/**
 * Peeks at the stack and returns the value stored at the top of the stack.
 * 
 * @param stack the stack to peek or check the top/first value
 * @param out where to return the value stored at the top of the stack
 * 
 * @return 1 if succesfully peeked/stored to out, STACK_EMPTY if stack if empty, STACK_ERROR if the process falls under none of these conditions.
 * @note The value of *out remains unchanged if the process is unsuccessful.
 */
stackerr_t sfirst(point_sp stack, Point **out);

/**
 * Peeks at the stack and returns the value stored at the next to the of the stack.
 * 
 * @param stack the stack to peek or check the second/next-to-top value
 * @param out where to return the value stored at the second of the stack
 * 
 * @return 1 if succesfully peeked/stored to out, STACK_EMPTY if stack if empty, STACK_ERROR if the process falls under none of these conditions.
 * @note The value of *out remains unchanged if the process is unsuccessful.
 */
stackerr_t ssecond(point_sp stack, Point **out);

/**
 * Allocates an array to put all the contents of the stack. This does not affect the original stack
 * 
 * @param stack the stack to copy into array
 * @param out pointer to an address where the new array would be allocated into
 * 
 * @return number of elements allocated into array if successful, 
 * @return STACK_EMPTY if stack has no elements to copy to array;
 * @return otherwise, STACK_ERROR
 * @note Address pointed to by *out remains unchanged if the process is unsuccessful.
 */
stackerr_t sarray(point_sp *stack, Point **out);

/**
 * Destroys or unallocates the stack along with the nodes stored within it
 * 
 * @param pstack pointer to the stack to destroy
 * 
 * @return 1 if successful,
 * @return 0 if the stack passed through the parameter is NULL, i.e. already destroyed
 * @return STACK_ERROR if the stack is not fully disposed due to invalidity.
 */
stackerr_t sdestroy(point_sp *pstack);

#endif
