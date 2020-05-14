#include "monty.h"
/**
 * _add - add the top two elements of the stack
 * @stack: stack
 * @line: line number
 */

void _add(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: cant add stack too short\n", line);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}

