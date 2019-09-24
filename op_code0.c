#include "monty.h"
#include <stdlib.h>

/**
 * push - adds a new node to the beginning of the linked list
 * @head: beginning of linked list
 * @n: Value for new node
 * Return: the new node that was added
 */
stack_t *push(stack_t **head, int n, unsigned int line_n)
{
	stack_t *new;

	if (line_n)
		line_n = line_n;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
 * pall - prints doubly linked list
 * @h: start of doubly linked list
 * Return: the number of nodes
 */
void pall(stack_t **stack, unsigned int line_n)
{
	stack_t *h = *stack;

	if (line_n)
                line_n = line_n;
	for (; h; h = h->next)
		printf("%d\n", h->n);
}

/**
 * pint - prints first node of linked list
 * @h: first node of linked list
 */
void pint(stack_t **stack, unsigned int line_n)
{
	stack_t *h = *stack;

	if (line_n)
                line_n = line_n;
	printf("%d\n", h->n);

}

/**
 * pop - removes first node of a linked list
 * @head: first node of linked list
 * Return: 1 if succesfull -1 if failed
 */
void pop(stack_t **stack, unsigned int line_n)
{
	stack_t *delete = *stack;

	if (line_n)
                line_n = line_n;
	*stack = delete->next;
	free(delete);
}
