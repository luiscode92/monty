#include "monty.h"
/**
 * get_opcode - opcode to execute
 * @stack: stack
 * @str: string with the opcode
 * @line:line number
 * Return: name of the opcode
 */

void (*get_opcode(stack_t **stack, char *str, int line))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	int i = 0;
	unsigned int j;

	while (ops[i].opcode)
	{
		for (j = 0; j < strlen(str); j++)
		{
			if (str[j] == '\n')
			{
				str[j] = '\0';
			}
		}
		if (strcmp(ops[i].opcode, str) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}

	dprintf(STDERR_FILENO, "%u: unknown instruction %s\n", line, str);
	free_all(stack);
	exit(EXIT_FAILURE);

}
