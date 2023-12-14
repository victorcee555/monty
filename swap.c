#include "monty.h"

/**
 * swap -  swaps the top two elements of the stack
 * @stack: pointer to a pointer to a stack
 * @line_number: current line number
 *
 * Return: anything
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *node_data1, *node_data2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	node_data1 = *stack;
	node_data2 = node_data1->next;

	temp = node_data1->n;
	node_data1->n = node_data2->n;
	node_data2->n = temp;
}
