#include "monty.h"

/**
  * free_dlistint - free doubly linked list
  * @head: start of doubly linked list
  */

void free_stack(stack_t *head)
{
	stack_t *hold;

		while (head)
		{
			hold = head;
			head = (*head).next;
			free(hold);
		}
}
