#include "monty.h"
#include <stdlib.h>

/**
 * push - adds a new node to the beginning of the linked list
 * @head: beginning of linked list
 * @n: Value for new node
 * Return: the new node that was added
 */
stack_t *push(stack_t **head, int n)
{
	stack_t *new;

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
size_t pall(stack_t *h)
{
	size_t size = 0;

	for (; h; h = h->next, size++)
		printf("%d\n", h->n);
	return (size);
}

/**
 * pint - prints first node of linked list
 * @h: first node of linked list
 */
void pint(stack_t *h)
{
	printf("%d\n", h->n);
}

