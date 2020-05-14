#include "monty.h"
/**
 * _push - push function
 * @stack: stack
 * @line: line number
 */

void _push(stack_t **stack, unsigned int line)
{
	char ar[128] = "";
	char *arg = ar;
	int value;
	unsigned int i;

	arg = strtok(NULL, " \t");
	if (arg)
	{
		if (arg[0] == '\n')
			error(stack, line);
		for (i = 0; i < strlen(arg); i++)
		{
			if (!isdigit(arg[i]) && arg[0] != '-' && arg[i] != '\n')
				error(stack, line);
		}
		value = atoi(arg);
	}
	else
		error(stack, line);

	if (global.queue)
		add_node_end(stack, value);
	else
		add_node(stack, value);
}

/**
 * error -  print error
 * @stack:  stack
 * @line: line number
 */
void error(stack_t **stack, unsigned int line)
{
	dprintf(STDERR_FILENO, "L%u:usage:push integer\n", line);
	free_all(stack);
	exit(EXIT_FAILURE);
}

/**
 * add_node - add a  node on the stack
 * @stack: stack
 * @value: node value
 */
void add_node(stack_t **stack, int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Erros: malloc failed\n");
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * add_node_end - add a node to te end of queue
 * @stack: stack
 * @value: node value
 */
void add_node_end(stack_t **stack, int value)
{
	stack_t *last = *stack;
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error:malloc failed\n");
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		new_node->prev = NULL;
		*stack = new_node;
		return;
	}
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}