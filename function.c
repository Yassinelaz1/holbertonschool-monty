#include "monty.h"
/**
 * print_all - task 0: Adds a node to the stack.
 * @stack: Pointer to a pointer to the top node of the stack.
 * @line_number: line number of  the opcode.
 * Return: void
*/
void print_all(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * push_in_stack- Add a node to the stack
 * @value: value
 * @stack: pointer to the top of the stack
 * Return: void
*/
void push_in_stack(stack_t **stack, unsigned int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	char *op;
	int numb;
	(void)value;
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	op=strtok(NULL," /n/t");
	numb=atoi(op);
	new_node->n = numb;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * _pint- task 0: Print top node of the stack.
 * @stack: Pointer to a pointer to the top node of the stack.
 * @line_number: line number of the opcode.
 * Return: void
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL )
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * _add- Add the top two elements of the stack.
 * @stack: Pointer to a pointer to the top node of the stack.
 * @line_number: line number of the opcode.
 * Return:void
*/
void _add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
