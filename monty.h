#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_node
{
    int value;
    struct stack_node *prev;
    struct stack_node *next;
} stack_t;

typedef struct data_bus
{
    char *argument;
    FILE *data_file;
    char *content;
    int lifi_flag;
} data_t;

extern data_t data_bus;

typedef struct opcode_instruction
{
    char *opcode;
    void (*func)(stack_t **stack, unsigned int line_number);
} opcode_instr_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t get_stdin(char **lineptr, int file);
char *clean_line(char *content);
void push_func(stack_t **head, unsigned int number);
void pall_func(stack_t **head, unsigned int number);
void pint_func(stack_t **head, unsigned int number);
int execute_instruction(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack_nodes(stack_t *head);
void pop_func(stack_t **head, unsigned int counter);
void swap_func(stack_t **head, unsigned int counter);
void add_func(stack_t **head, unsigned int counter);
void nop_func(stack_t **head, unsigned int counter);
void sub_func(stack_t **head, unsigned int counter);
void div_func(stack_t **head, unsigned int counter);
void mul_func(stack_t **head, unsigned int counter);
void mod_func(stack_t **head, unsigned int counter);
void pchar_func(stack_t **head, unsigned int counter);
void pstr_func(stack_t **head, unsigned int counter);
void rotl_func(stack_t **head, unsigned int counter);
void rotr_func(stack_t **head, __attribute__((unused)) unsigned int counter);
void add_node(stack_t **head, int value);
void add_queue(stack_t **head, int value);
void queue_func(stack_t **head, unsigned int counter);
void stack_func(stack_t **head, unsigned int counter);

#endif

