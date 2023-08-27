#include "monty.h"

/**
 * f_rotl - rotates the stack to the top
 * @stack_head: stack head
 * @line_num: line_number
 * Return: no return
 */
void f_rotl(stack_t **stack_head, __attribute__((unused)) unsigned int line_num)
{
    stack_t *tmp = *stack_head, *new_head;

    if (*stack_head == NULL || (*stack_head)->next == NULL)
    {
        return;
    }
    new_head = (*stack_head)->next;
    new_head->prev = NULL;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = *stack_head;
    (*stack_head)->next = NULL;
    (*stack_head)->prev = tmp;
    (*stack_head) = new_head;
}

