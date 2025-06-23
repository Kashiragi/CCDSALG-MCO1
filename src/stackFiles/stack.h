#include "stdlib.h"
#include "assert.h"
#include "stdbool.h"
#include "globals.h"

// Max stack is 2^15 = 32768.
#define MAX_STACK (1<<15)

// Error codes

// "STAC(K) OVER(load)". Stack has reached its upper limit.
#define STACK_FULL -0X57AC05E7
// "STAC(K) ZERO". Stack has zero nodes.
#define STACK_EMPTY -0x57AC2E70
// "STAC(K) SOLO". Exclusively for ssecond(). 
// There is only one node in the stack and no second node to seek.
#define STACK_NOSECOND -0x57AC5010
// "STAC(K) CORR(upted)". Stack is invalid or not working as intended.
#define STACK_ERROR -0x57ACC077

/// <summary>
/// Creates a new stack instance.
/// </summary>
/// <param name="stack">- Pointer to the stack.</param>
/// <returns>Returns 1 if the stack is successfully allocated, 0 otherwise.</returns>
bool screate(int_sp *stack);

/// <summary>
/// Checks if the stack is full.
/// </summary>
/// <param name="stack">- Stack to check.</param>
/// <returns>Returns 1 if the stack is full, 0 if not.</returns>
bool sfull(int_sp stack);

/// <summary>
/// Checks if the stack is empty.
/// </summary>
/// <param name="stack">- Stack to check.</param>
/// <returns>Returns 1 if the stack is empty, 0 if not.</returns>
bool sempty(int_sp stack);

/// <summary>
/// Pushes a value to the top of the stack.
/// </summary>
/// <param name="pstack">- Pointer to an existing stack.</param>
/// <param name="value">- Value to push.</param>
/// <returns>
/// Returns 1 if stored successfully,
/// STACK_FULL if the stack is full for which the value can no longer be pushed,
/// and STACK_ERROR if the stack is invalid.
/// </returns>
stackerr_t spush(int_sp *pstack, int value);

/// <summary>
/// Takes the top of the stack and retracts it if there are any more values.
/// </summary>
/// <param name="pstack">- Pointer to an existing stack.</param>
/// <param name="out">- Variable where to store the value of the retrieved node.</param>
/// <returns>
/// If successful, returns 1, and the retrieved value is stored into *out.
/// Returns STACK_EMPTY if the function attempts to be executed on an empty stack,
/// and STACK_ERROR if the stack is invalid.
/// The value of *out remains unchanged if the process is unsuccessful.
/// </returns>
stackerr_t spop(int_sp *pstack, int *out);

/// <summary>
/// Peeks at the stack and returns the value stored at the top of the stack.
/// </summary>
/// <param name="stack">- Stack to peek at.</param>
/// <returns>
/// If successful, returns 1, and the value stored in the top node of the stack is stored into *out.
/// If the stack is empty, returns STACK_EMPTY.
/// Returns STACK_ERROR if the process falls under none of these conditions.
/// The value of *out remains unchanged if the process is unsuccessful.
/// </returns>
stackerr_t sfirst(int_sp stack, int *out);

/// <summary>
/// Peeks at the stack and returns the value stored before the top of the stack.
/// </summary>
/// <param name="stack">- Stack to peek at.</param>
/// <returns>
/// If successful, returns 1, and the value stored before the top node of the stack is stored into *out.
/// If there is no second node, returns STACK_SOLO.
/// If the stack is empty, returns STACK_EMPTY.
/// Returns STACK_ERROR if the process falls under none of these conditions.
/// The value of *out remains unchanged if the process is unsuccessful.
/// </returns>
stackerr_t ssecond(int_sp stack, int *out);

/// <summary>
/// Collapses a stack along with the nodes stored within it.
/// </summary>
/// <param name="pstack">- Pointer to the stack to destroy.</param>
/// <returns>
/// Returns 1 if successful,
/// 0 if the stack passed through the parameter is NULL, i.e. already destroyed,
/// and STACK_ERROR if the stack is not fully disposed due to invalidity.
/// </returns>
stackerr_t sdestroy(int_sp *pstack);