#include "monty.h"

/**
 * execute - executes the opcode
 * @stack_top: head linked list - stack
 * @line_counter: line_counter
 * @data_file: pointer to monty file
 * @line_content: line content
 * Return: no return
 */
int execute(char *line_content, stack_t **stack_top, unsigned int line_counter, FILE *data_file)
{
    opcode_instr_t op_instructions[] = {
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
    char *opcode;

    opcode = strtok(line_content, " \n\t");
    if (opcode && opcode[0] == '#')
        return (0);
    bus.arg = strtok(NULL, " \n\t");
    while (op_instructions[i].opcode && opcode)
    {
        if (strcmp(opcode, op_instructions[i].opcode) == 0)
        {
            op_instructions[i].func(stack_top, line_counter); // Use "func" instead of "f"
            return (0);
        }
        i++;
    }
    if (opcode && op_instructions[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, opcode);
        fclose(data_file);
        free(line_content);
        free_stack(*stack_top);
        exit(EXIT_FAILURE);
    }
    return (1);
}

