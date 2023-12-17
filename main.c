#include "monty.h"

/**
 * read_execute - executes the functions
 * @file: the variable which streams the monty file
 *
 * Return: 1
 */

int read_execute(FILE *file)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
	};
	line_number = 0;
	instruct_len = sizeof(instructions) / sizeof(instructions[0]);
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		if (sscanf(line, "%s", instruction) == 1)
			if (strcmp(instruction, "push") == 0)
			{
				get_input = sscanf(line, "%*s%d", &value);
				if (get_input != 1)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}

				strtol(line + 5, &endptr, 10);
				if (*endptr != '\n' && *endptr != '\0')
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
				}
			}
		found = 0;
		for (i = 0; i < instruct_len; i++)
			if (strcmp(instructions[i].opcode, instruction) == 0)
			{
				instructions[i].f(&stack, line_number);
				found = 1;
				break;
			}
		if (!found)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

/**
 * main - A monty interpreter.
 *
 * @argc: argument count
 * @argv: a pointer to an array of strings containing the arguments.
 *
 * Return: 0.
 */

int main(int argc, char **argv)
{
	FILE *file;

	stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (!read_execute(file))
	{
		fclose(file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	fclose(file);
	free_stack(stack);
	return (0);
}

