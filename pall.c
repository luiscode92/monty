#include "monty.h"
/**
 * _pall - print values ont he stack
 * @stack: stack
 * @line: line numebr
 */
void _pall(stack_t **stack, unsigned int line)
{
	stack_t *print = *stack;

	(void) line;

	while (print != NULL)
	{
		printf("%d\n", print->n);
		print = print->next;
	}
}