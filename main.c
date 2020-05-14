#include "monty.h"

global_t global = {NULL, 0};

/**
 * main - Main function
 * @argc: argument
 * @argv: arguments
 * Return: 0 for success, 1 otherwise
 */
int main(int argc, char **argv)
{
	char buffer[1024];
	char t[128] = " ";
	char *token = t;
	stack_t *stack = NULL;
	unsigned int line = 1;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.fp = fopen(argv[1], "r");
	if (!(global.fp))
	{
		dprintf(STDERR_FILENO, "Error: Can't open file%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), global.fp) != NULL)
	{
		token = strtok(buffer, " \t");
		if (token[0] == '#')
		{
			printf("fuck");
			free(token);
		}
		else if (token[0] != '\n')
		{
			get_opcode(&stack, token, line)(&stack, line);
		}
		line++;
	}
	free_all(&stack);
}
