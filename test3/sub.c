#include "monty.h"

/**
 * f_sub - subtraction
 * @stack_head: stack head
 * @line_num: line_number
 * Return: no return
 */
void f_sub(stack_t **stack_head, unsigned int line_num)
{
    stack_t *current;
    int result, num_nodes;

    current = *stack_head;
    for (num_nodes = 0; current != NULL; num_nodes++)
        current = current->next;

    if (num_nodes < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }

    current = *stack_head;
    result = current->next->n - current->n;
    current->next->n = result;
    *stack_head = current->next;
    free(current);
}

