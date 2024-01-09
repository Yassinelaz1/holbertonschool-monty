#include "monty.h"
/**
 *_pop - removes the top element of the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_number:  the line number of of the opcode.
 * Return: void
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
/**
 * nothing - Do nothing.
 * @stack: unuseful variable in this function.
 * @line_number: unuseful variable in this function.
 */
void nothing(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
