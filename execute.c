#include "monty.h"

int execute(char *line_content, stack_t **data_stack, unsigned int line_counter, FILE *data_file)
{
    instruction_t op_instructions[] = {
        {"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
        {"pop", f_pop},
        {"swap", f_swap},
        {"add", f_add},
        {"nop", f_nop},
        {"sub", f_sub},
        {"div", f_div},
        {"mul", f_mul},
        {"mod", f_mod},
        {"pchar", f_pchar},
        {"pstr", f_pstr},
        {"rotl", f_rotl},
        {"rotr", f_rotr},
        {"queue", f_queue},
        {"stack", f_stack},
        {NULL, NULL}
    };
    unsigned int i = 0;
    char *operation;

    operation = strtok(line_content, " \n\t");
    if (operation && operation[0] == '#')
        return 0;
    data_bus.argument = strtok(NULL, " \n\t");
    while (op_instructions[i].opcode && operation)
    {
        if (strcmp(operation, op_instructions[i].opcode) == 0)
        {
            op_instructions[i].func(data_stack, line_counter);
            return 0;
        }
        i++;
    }
    if (operation && op_instructions[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, operation);
        fclose(data_file);
        free(line_content);
        free_stack(*data_stack);
        exit(EXIT_FAILURE);
    }
    return 1;
}

