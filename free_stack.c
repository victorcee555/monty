#include "monty.h"

/**
 * free_stack - A function that frees a stack
 *
 * @stack: a pointer to the stack
 *
 * Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
