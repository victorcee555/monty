#include "monty.h"

/**
 *add -  adds the top two elements of the stack.
 *@stack: pointer to a pointer of a stack.
 *@line_number: line number
 *
 *Return: nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *num1, *num2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	num1 = *stack;
	num2 = num1->next;

	num2->n += num1->n;

	*stack = num2;
	(*stack)->prev = NULL;

	free(num1);
}
