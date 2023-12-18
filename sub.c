#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second
 * @stack: pointer to a pointer to a stack
 * @line_number: current line number
 *
 * Return: nothing
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *num1, *num2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	num1 = *stack;
	num2 = num1->next;

	num2->n -= num1->n;
	*stack = num2;
	(*stack)->prev = NULL;

	free(num1);
}
