#include "monty.h"

/**
 * pall - prints all the elements on the stack.
 * @stack: a pointer to a pointer to the stack;
 * @line_number: The line number of the file read.
 *
 * Return: void.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_elm;

	(void)line_number;

	if (*stack == NULL)
		return;

	stack_elm = *stack;

	while (stack_elm != NULL)
	{
		printf("%d\n", stack_elm->n);
		stack_elm = stack_elm->next;
	}
}
