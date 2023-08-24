#include "monty.h"


/**
 * handle_instruction - check the instruction.
 * @instruction: the instruction line.
 * Return: 0 when it fails 1 on success.
 */
int handle_instruction(char *instruction)
{
	char *inst_name;
	/* char *arg; */
	int i = 0;
	instruction_t ins_func[] = {
		{"push", NULL}, {NULL, NULL}
	};

	inst_name = strtok(instruction, " \n\t");
	if ((inst_name && inst_name[0] == '#') || !inst_name)
		return (0);
	/* arg = strtok(NULL, " \n\t"); */
	while (ins_func[i].opcode != NULL)
	{
		if (strcmp(inst_name, ins_func[i].opcode) == 0)
		{
		}
		i++;
	}
	return (1);
}

/**
 * main - Entry point.
 * @argc: number of command line arguments.
 * @argv: the command line arguments.
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *instruction;
	size_t read_l = 1;
	size_t size = 0;

	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_l > 0)
	{
		instruction = NULL;
		read_l = getline(&instruction, &size, file);
		if (read_l)
			handle_instruction(instruction);
		free(instruction);
	}
	fclose(file);
	return (0);
}
