#include "monty.h"



int main(int argc, char **argv)
{
    stack_t *stack = NULL;
    instruction_t instructions[] = {
		{"push", push_in_stack},
        {"pall", print_all},
        {"nop",nothing},
		{NULL, NULL}};
    char *opcode;
    int i;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    
    char *line = NULL;
    size_t len = 0;

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    while (getline(&line, &len, fp) != -1)
    {
        line_number++;
        opcode = strtok(line, " $\n");
        if (opcode == NULL)
            continue;

        for (i = 0; instructions[i].opcode; i++)
        {
            if (strcmp(instructions[i].opcode, opcode) == 0)
            {
                instructions[i].f(&stack, line_number);
                break;
            }
        }

        if (instructions[i].opcode == NULL)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            free_stack(stack);
            return (EXIT_FAILURE);
        }
    }

    free(line);
    fclose(fp);
    free_stack(stack);
    return (0);
}

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
