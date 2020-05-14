#include "monty.h"
/**
 * _pop - remove top element of the stack
 * @stack: stack
 * @line: line numebr
 */

void _pop(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (*stack != NULL)
	{
		tmp = *stack;
		if ((*stack)->next)
			(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		free(tmp);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u:can't pint, stack empty", line);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}
