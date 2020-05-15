#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: stack
 * @line: line number
 */

void _swap(stack_t **stack, unsigned int line)
{
	int tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}
