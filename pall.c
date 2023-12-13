#include "monty.h"

/**
 * pall - prints all the elements on the stack.
 *
 * @stack: a pointer to a pointer to the stack;
 * @line_number: The line number of the file read.
 *
 * Return: void.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack;

	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		fprintf(stderr, "Error");
	}
}
