#include "monty.h"
#include <stdlib.h>

/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current_top = *stack;
	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	current_top->next->prev = NULL;

	while (current_top->next)
		current_top = current_top->next;

	current_top->next = *stack;
	*stack = (*stack)->next;
	current_top->next->next = NULL;
	current_top->next->prev = current_top;
}


/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom_element;
	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	bottom_element = *stack;
	while (bottom_element->next)
		bottom_element = bottom_element->next;

	bottom_element->next = *stack;
	bottom_element->prev->next = NULL;
	bottom_element->prev = NULL;

	(*stack)->prev = bottom_element;
	*stack = bottom_element;
}

/**
 * stack - Set the mode to stack (LIFO).
 * @stack: A pointer to the stack.
 * @line_number: The line number (unused in this function).
 */

void stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;

	var.MODE = 0;

}

/**
 * queue - Set the mode to queue (FIFO).
 * @stack: A pointer to the stack.
 * @line_number: The line number (unused in this function).
 */

void queue(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	var.MODE = 1;

}
