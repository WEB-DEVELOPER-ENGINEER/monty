#include "monty.h"

/**
 * push - add new node
 * @stack: Head of the linked list.
 * @line_number: line num
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *value;
	int operator;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	value = strtok(NULL, " \n\t\r");
	operator = manage_error(value, line_number);
	new_node->n = operator;
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new_node, new_node->next = NULL;
		return;
	}
	(*stack)->prev = new_node;
	new_node->next = *stack;
	*stack = new_node;
}
