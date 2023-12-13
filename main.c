#include "monty.h"

stack_t *stack = NULL;

int main(int argc, char **argv)
{
	FILE *file;
	unsigned int line_number;
	int i;
	char line[100], instructions[100];

	/** An array of type struct instruction_t the stores opcode
	 * and its respective functions **/
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
	};

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
					instruction[i].f(&stack, line_number);
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

	fclose(file);
	if (line)
		free(line);
	else
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
