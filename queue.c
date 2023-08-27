#include "monty.h"

void set_queue_mode(stack_t **stack_top, unsigned int line_number)
{
    (void)stack_top;
    (void)line_number;
    data_bus.lifi_flag = 1;
}

void add_to_queue(stack_t **stack_head, int new_value)
{
    stack_t *new_node, *current;

    current = *stack_head;
    new_node = malloc(sizeof(stack_t));
    
    if (new_node == NULL)
    {
        printf("Error\n");
    }

    new_node->n = new_value;
    new_node->next = NULL;

    if (current)
    {
        while (current->next)
            current = current->next;
    }

    if (!current)
    {
        *stack_head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        current->next = new_node;
        new_node->prev = current;
    }
}

