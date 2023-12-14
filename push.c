#include "monty.h"

/**
 * push - A function to add ontop of the stack.
 *
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The line number from the monty file.
 *
 * Return: void.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack;

	(void)line_number;
	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		free(new_stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_stack->n = value;
	new_stack->next = *stack;
	new_stack->prev = NULL;
	if ((*stack) != NULL)
		(*stack)->prev = new_stack;
	(*stack) = new_stack;

	printf("%d\n", new_stack->n);
}
