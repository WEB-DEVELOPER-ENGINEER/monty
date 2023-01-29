#include "monty.h"

/**
 * _mod - get the module of the top by the second top.
 * @stack: Head of the doubly linked list.
 * @line_number: Line to execute
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	int res;

	stack_t *tmp = *stack;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	res = tmp->n % (*stack)->n;
	free(*stack);
	*stack = tmp;
	(*stack)->n = res;
}
