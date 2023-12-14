#include "monty.h"

/**
 * read_execute - executes the functions
 * @file: the variable which streams the monty file
 *
 * Return: 1
 */

int read_execute(FILE *file)
{
	unsigned int line_number;
	int i;
	char line[100], instruction[100];

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop",nop},
	};

	value = 0;
	line_number = 1;
	instruct_len = sizeof(instructions) / sizeof(instructions[0]);

	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (sscanf(line, "%s" "%d", instruction, &value) == 2)
			for (i = 0; i < instruct_len; i++)
			{
				if (strcmp(instructions[i].opcode, instruction) == 0)
				{
					instructions[i].f(&stack, line_number);
					break;
				}
			}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	return (1);
}

/**
 * main - A monty interpreter.
 *
 * @argc: argument count
 * @argv: a pointer to an array of strings containing the argumets.
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
		exit(EXIT_FAILURE);
	}

	fclose(file);
	return (0);
}
