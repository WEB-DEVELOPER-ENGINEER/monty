#include "monty.h"
#define _GNU_SOURCE
#include <stdio.h>

/**
 * function_select - select the fucntion
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * @command: The command passed.
 */
void function_select(stack_t **stack, unsigned int line_number, char *command)
{
	instruction_t functions[] = {
		{"pint", pint}, {"pall", pall}, {"push", push},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", _rotl}, {"rotr", _rotr}
	};
	int j;

	if (command[0] == '#')
		return;
	for (j = 0; functions[j].opcode != NULL; j++)
	{
		if (strcmp(functions[j].opcode, command) == 0)
		{
			functions[j].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, command);
	exit(EXIT_FAILURE);
}

/**
 * find_file - Mange of the path for know the function for use.
 * @stack: Head of the double linked list.
 * @path: The file with commands.
 */

void find_file(char *path, stack_t **stack)
{
	FILE *file;
	char *command;
	unsigned int line_number = 1;
	char buffer[128];

	if (!path)
	{
		fprintf(stderr, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}
	file = fopen(path, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}
	header.file = file;
	while ((fgets(buffer, 128, file)) != NULL)
	{
		header.buffer = buffer;
		command = strtok(buffer, " \n\t\r");
		if (command)
			function_select(stack, line_number, command);
		line_number++;
	}
	free_all();

	/* free(buffer); */

	/* fclose(file); */

	exit(EXIT_SUCCESS);

}
