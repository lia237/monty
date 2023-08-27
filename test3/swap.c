#include "monty.h"

/**
 * f_swap - swaps the top two elements of the stack.
 * @stack_head: stack head
 * @line_num: line_number
 * Return: no return
*/
void f_swap(stack_t **stack_head, unsigned int line_num)
{
    stack_t *current;
    int stack_len = 0, temp_value;

    current = *stack_head;
    while (current)
    {
        current = current->next;
        stack_len++;
    }

    if (stack_len < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }

    current = *stack_head;
    temp_value = current->n;
    current->n = current->next->n;
    current->next->n = temp_value;
}

