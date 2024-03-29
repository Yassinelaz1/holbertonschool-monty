#ifndef monty
#define monty

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "monty.h"
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its functionmonty.h
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void free_stack(stack_t *stack);
void print_all(stack_t **stack, unsigned int line_number);
void push_in_stack(stack_t **stack, unsigned int value);
void nothing(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);

#endif
