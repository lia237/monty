#include "monty.h"
#include <ctype.h>

/**
 * free_stack - frees a stack
 * @stack: double pointer to the stack
 */

void free_stack(stack_t **stack)
{
    while (*stack)
    {
        stack_t *temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

/**
 * isnum - checks if a string is a number
 * @str: the string to check
 * Return: 1 if true, 0 otherwise
 */

int isnum(const char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;

    while (str[i] != '\0')
    {
        if (!isdigit(str[i]))
            return 0;
        i++;
    }

    return 1;
}

