#include "monty.h"

void free_stack(stack_t *stack)
{
	stack_t *temp;

	if (stack == NULL)
		return;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
