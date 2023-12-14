#include "monty.h"

/**
 * pint -  prints the value at the top of the stack, followed by a new line
 * @stack: pointer to a pointer to a stack
 * @line_number: current line number
 *
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	free(*stack);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
