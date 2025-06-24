#ifndef STACK_H
#define STACK_H
#include "../globals.h"

/// <summary>
/// Creates a new stack instance.
/// </summary>
/// <param name="stack">- Pointer to the stack.</param>
/// <returns>Returns 1 if the stack is successfully allocated, 0 otherwise.</returns>
bool screate(point_sp *stack);

/// <summary>
/// Checks if the stack is full.
/// </summary>
/// <param name="stack">- Stack to check.</param>
/// <returns>Returns 1 if the stack is full, 0 if not.</returns>
bool sfull(point_sp stack);

/// <summary>
/// Checks if the stack is empty.
/// </summary>
/// <param name="stack">- Stack to check.</param>
/// <returns>Returns 1 if the stack is empty, 0 if not.</returns>
bool sempty(point_sp stack);

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
stackerr_t spush(point_sp *pstack, Point value);

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
stackerr_t spop(point_sp *pstack, Point *out);

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
stackerr_t sfirst(point_sp stack, Point **out);

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
stackerr_t ssecond(point_sp stack, Point **out);

/// <summary>
/// Collapses a stack along with the nodes stored within it.
/// </summary>
/// <param name="pstack">- Pointer to the stack to destroy.</param>
/// <returns>
/// Returns 1 if successful,
/// 0 if the stack passed through the parameter is NULL, i.e. already destroyed,
/// and STACK_ERROR if the stack is not fully disposed due to invalidity.
/// </returns>
stackerr_t sdestroy(point_sp *pstack);

#endif
