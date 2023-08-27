#include "monty.h"

void add_new_node(stack_t **stack_top, int new_value)
{
    stack_t *new_node, *temp;

    temp = *stack_top;
    new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        printf("Error\n");
        exit(0);
    }

    if (temp)
        temp->prev = new_node;

    new_node->n = new_value;
    new_node->next = *stack_top;
    new_node->prev = NULL;
    *stack_top = new_node;
}

