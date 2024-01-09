#include "monty.h"

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

void push_in_stack(stack_t **stack, unsigned int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
    {
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}
void nothing(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}