#include "monty.h"
/**
 * _pint - print value t the top of stack
 * @stack: stack
 * @line: line number
*/
void _pint(stack_t **stack, unsigned int line)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		dprintf(STDERR_FILENO, "L%u: cant pint,stack empty\n ", line);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}
