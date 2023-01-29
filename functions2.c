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

/**
 * nop - Do nothing.
 * @stack: Head of the doubly linked list.
 * @line_number: line num
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - substract the top by the second top.
 * @stack: Head of the doubly linked list.
 * @line_number: Line num
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int res, i;

	stack_t *tmp = *stack;

	for (i = 0; tmp != NULL; i++)
		tmp = tmp->next;
	if (i < 2 || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	res = tmp->n - (*stack)->n;
	free(*stack);
	*stack = tmp;
	(*stack)->n = res;
}

/**
 * _div - divide the top by the second top.
 * @stack: Head of the doubly linked list.
 * @line_number: Line num
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int res;

	stack_t *tmp = *stack;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	res = tmp->n / (*stack)->n;
	free(*stack);
	*stack = tmp;
	(*stack)->n = res;
}

/**
 * _mul - multiplicate the top by the second top.
 * @stack: Head of the doubly linked list.
 * @line_number: The line to execute
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	int res;

	stack_t *tmp = *stack;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	res = (*stack)->n * tmp->n;
	free(*stack);
	*stack = tmp;
	(*stack)->n = res;
}
