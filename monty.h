#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct argument_container
{
    char *arguments;
    int stack_queue;
} argument_container_t;

typedef struct stack_node
{
    int n;
    struct stack_node *next;
} stack_t;

extern argument_container_t argument_container;

int isnum(const char *str);
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);

#endif

