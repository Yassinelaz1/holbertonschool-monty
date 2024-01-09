#include "monty.h"
/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	instruction_t instructions[] = {
		{"push", push_in_stack}, 
		{"pall", print_all}, 
		{"pint", _pint}, 
		{"pop", _pop}, 
		{"add", _add}, 
		{"nop", nothing}, 
		{NULL, NULL}};
	char *opcode;
	int i;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	char *line = NULL;
	size_t len = 0;
	FILE *fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, fd) != -1)
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
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	fclose(fd);
	free_stack(stack);
	return (0);
}
