#include "monty.h"
/**
 * f_pint - prints the top element of the stack
 * @stack_head: pointer to the head of the stack
 * @line_num: line number
 * Return: no return
*/
void f_pint(stack_t **stack_head, unsigned int line_num)
{
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->n);
}

