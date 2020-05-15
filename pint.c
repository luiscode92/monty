#include "monty.h"
/**
 * _pint - print value t the top of stack
 * @stack: stack
 * @line: line number
*/
void _pint(stack_t **stack, unsigned int line)
{
	if (*stack)
	{
		//printf("pint if");
		printf("%d\n", (*stack)->n);
	}
	else
	{
		//printf("pint else");
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}
