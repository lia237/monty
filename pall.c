#include "monty.h"

/**
 * op_pall - prints out the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current_node;

    (void)line_number;
    
    if (!*stack)
        return;
    
    current_node = *stack;
    while (current_node != NULL)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->next;
    }
}

