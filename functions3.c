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

/**
 * pchar - Print ascii character.
 * @stack: Head of the doubly linked list.
 * @line_number: Line to execute
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 32 || (*stack)->n > 126)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * _rotl - rotates the stack to the top.
 * @stack: Head of the doubly linked list.
 * @line_number: Line to execute
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1;

	stack_t *tmp2;

	if (!stack || !(*stack) || !(*stack)->next)
		return;
	(void)line_number;
	tmp1 = *stack;
	tmp2 = *stack;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	*stack = tmp2->next;
	(*stack)->prev = tmp2->prev;
	tmp2->next = tmp1->next;
	tmp1->next = tmp2;
	tmp2->prev = tmp1;
}

/**
 * _rotr - rotates the stack to the bottom.
 * @stack: Head of the doubly linked list.
 * @line_number: Line of execution
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *final, *b_final;

	if (!stack || !(*stack) || !(*stack)->next)
		return;
	(void)line_number;
	tmp = *stack;
	final = *stack;
	while (final->next != NULL)
		final = final->next;
	b_final = final->prev;
	b_final->next = final->next;
	final->next = tmp;
	final->prev = tmp->prev;
	tmp->prev = final;
	*stack = final;
}

/**
 * pstr - print string
 * @stack: Addres of first element of stack
 * @line_number: Num of line
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack);

	(void)line_number;

	if (!stack || !(*stack))
		goto exi;
	while (tmp)
	{
		if (tmp->n == 0)
			return;
		if (tmp->n < 32 || tmp->n > 126)
			return;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
exi: printf("\n");
}
