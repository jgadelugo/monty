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
int pall(stack_t **stack, unsigned int line_n)
{
	if (!*stack)
		return (-1);
	for (; h; h = h->next)
		printf("%d\n", h->n);
	return (1);
}

/**
 * pint - prints first node of linked list
 * @h: first node of linked list
 */
int pint(stack_t **stack, unsigned int line_n)
{
	if (!*stack)
		return (-1);
	printf("%d\n", h->n);

	return (1);
}

/**
 * pop - removes first node of a linked list
 * @head: first node of linked list
 * Return: 1 if succesfull -1 if failed
 */
int pop(stack_t **stack, unsigned int line_n)
{
	stack_t *delete = *head;

	if (*head == NULL)
		return (-1);
	*head = delete->next;
	free(delete);
	return(1);
}
