#include "monty.h"

/**
 * f_mul - multiplies the top two elements of the stack.
 * @stack: stack head
 * @counter: line_number
 * Return: no return
*/
void f_mul(stack_t **stack, unsigned int counter)
{
    stack_t *current;
    int length = 0, result;

    current = *stack;
    while (current)
    {
        current = current->next;
        length++;
    }

    if (length < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    current = *stack;
    result = current->next->n * current->n;
    current->next->n = result;
    *stack = current->next;
    free(current);
}

