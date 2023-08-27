#include "monty.h"

void add_operation(stack_t **stack_top, unsigned int line_number)
{
    stack_t *current;
    int stack_length = 0, result;

    current = *stack_top;
    while (current)
    {
        current = current->next;
        stack_length++;
    }

    if (stack_length < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack_top);
        exit(EXIT_FAILURE);
    }

    current = *stack_top;
    result = current->n + current->next->n;
    current->next->n = result;
    *stack_top = current->next;
    free(current);
}

