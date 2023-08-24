#include "monty.h"

/**
 * op_push - pushes integers to the stack
 * @stack: pointer to the stack
 * @line_number: the line number
 */

void op_push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    int n;

    if (!stack)
    {
        fprintf(stderr, "L%u: stack not found\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (!argument_container.arguments)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    if (!isnum(argument_container.arguments))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    n = atoi(argument_container.arguments);
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->next = *stack;
    *stack = new_node;
}

