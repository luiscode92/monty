#include "monty.h"
/**
 * free_all - free alla memory
 * @stack: stack
 */
void free_all(stack_t **stack)
{
	stack_t *tmp;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	fclose(global.fp);
}
