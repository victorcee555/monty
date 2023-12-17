#include "monty.h"

/**
 * mod - computes the rest of the division
 * @stack: pointer to a pointer to a stack
 * @line_number: current line number
 *
 * Return: nothing
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *num1, *num2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	num1 = *stack;
	num2 = num1->next;

	if (num1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	num2->n %= num1->n;
	*stack = num2;
	(*stack)->prev = NULL;

	free(num1);
}
