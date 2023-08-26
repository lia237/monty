#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <string.h>

/**
* main - exec Monty code
* @argc: number of command arguments
* @argv: vector of command arguments
* Return: EXIT_SUCCESS on success, EXIT_FAILURE on fail
*/

argument_container_t argument_container = {NULL, 0};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;

        char *token = strtok(line, " \t\n");
        if (token == NULL)
            continue;
        if (strcmp(token, "push") == 0)
        {
            token = strtok(NULL, " \t\n");
            if (token == NULL)
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                free_stack(&stack);
                exit(EXIT_FAILURE);
            }
            argument_container.arguments = token;
            op_push(&stack, line_number);
        }
        else if (strcmp(token, "pall") == 0)
        {
            op_pall(&stack, line_number);
        }
    }

    fclose(file);
    if (line)
        free(line);
    while (stack)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return 0;
}

