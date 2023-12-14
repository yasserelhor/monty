#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#define Buffsize 30

/**
 * struct stack_s - Doubly linked list node structure for a stack.
 * @n: Integer value stored in the node.
 * @prev: Pointer to the previous node in the stack.
 * @next: Pointer to the next node in the stack.
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Structure for an instruction in an interpreter.
 * @opcode: The opcode as a string.
 * @f: Pointer to the function that executes the instruction.
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct glob_var - Structure for global variables in an interpreter.
 * @file: Pointer to the current file being processed.
 * @buff: Pointer to a buffer for storing input lines.
 * @tmp: Temporary variable used for various purposes.
 * @dict: Pointer to the instruction dictionary.
 * @head: Pointer to the head of a stack.
 * @line_number: Current line number in the input file.
 * @MODE: Operating mode indicator (example: interactive, script).
 */

typedef struct glob_var
{
	FILE *file;
	char *buff;
	size_t tmp;
	instruction_t *dict;
	stack_t *head;
	unsigned int line_number;
	int MODE;
} vars;


extern vars var;

int start_vars(vars *var);
instruction_t *create_instru();
int call_funct(vars *var, char *opcode);
void free_all(void);
int _isdigit(char *string);

void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);

void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

#endif
