#include "monty.h"
#include <stdlib.h>
#include <ctype.h>
/**
 * mul - Multiplies the second top element of the stack with the top element.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}


/**
 * mod - Computes the remainder of the division of the second top element
 *       of the stack by the top element.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void mod(stack_t **stack, unsigned int line_number)
{
	int divisor;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	divisor = (*stack)->n;

	if (divisor == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= divisor;
	pop(stack, line_number);
}

/**
 * pchar - Prints the char at the top of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if (isprint(value))
	{
		printf("%c\n", value);
		return;
	}

	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (!stack || !*stack)
	{
		putchar('\n');
		return;
	}

	while (tmp && tmp->n != 0 && isprint(tmp->n))
	{
		putchar(tmp->n);
		tmp = tmp->next;
	}

	putchar('\n');
}
