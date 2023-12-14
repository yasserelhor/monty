#include "monty.h"
#include <stdlib.h>

/**
 * pall - Prints all the elements of a stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (!tmp)
		return;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *num = strtok(NULL, " \r\t\n");
	stack_t *tmp = NULL, *tm = *stack;

	if (num == NULL || (isdigit(*num) == 0 && *num != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		perror("Error: malloc failed");
		free_all();
		exit(EXIT_FAILURE);
	}

	tmp->n = atoi(num);

	if (var.MODE == 0 || !*stack)
	{
		tmp->next = *stack;
		tmp->prev = NULL;
		if (*stack)
			(*stack)->prev = tmp;
		*stack = tmp;
	}
	else
	{
		while (tm->next)
			tm = tm->next;

		tm->next = tmp;
		tmp->prev = tm;
		tmp->next = NULL;
	}
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all();

		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(tmp);
}
