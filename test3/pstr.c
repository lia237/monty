#include "monty.h"

/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @stack_head: stack head
 * @line_num: line_number
 * Return: no return
*/
void f_pstr(stack_t **stack_head, unsigned int line_num)
{
    stack_t *current_node;
    (void) line_num;

    current_node = *stack_head;
    while (current_node)
    {
        if (current_node->n > 127 || current_node->n <= 0)
        {
            break;
        }
        printf("%c", current_node->n);
        current_node = current_node->next;
    }
    printf("\n");
}

