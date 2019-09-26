#include "monty.h"

/**
 * rotl - top element becomes last second becomes top
 * @stack: top of the stack - doubly linked list
 * @line_n: line number
 */
void rotl(stack_t **stack, unsigned int line_n)
{
	stack_t *last = *stack, *head = *stack;

	if (line_n)
		line_n = line_n;
	if (head && head->next)
	{
		*stack = head->next;
		(*stack)->prev = NULL;
		for (; last->next; last = last->next)
			;
		last->next = head;
		head->next = NULL;
		head->prev = last;
	}
}

/**
 * rotr - last element becomes top
 * @stack: top of the stack - doubly linked list
 * @line_n: line number
 */
void rotr(stack_t **stack, unsigned int line_n)
{
	stack_t *last = *stack;

	if (line_n)
		line_n = line_n;
	if (*stack && (*stack)->next)
	{
		for (; last->next; last = last->next)
			;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}
