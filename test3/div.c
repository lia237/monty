#include "monty.h"

void divide_operation(stack_t **stack_top, unsigned int line_number)
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
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack_top);
        exit(EXIT_FAILURE);
    }

    current = *stack_top;
    if (current->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack_top);
        exit(EXIT_FAILURE);
    }

    result = current->next->n / current->n;
    current->next->n = result;
    *stack_top = current->next;
    free(current);
}

