#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Unused.
 * @line_n: Unused.
 */
void nop(stack_t **stack, unsigned int line_n)
{
	(void)*stack;
	(void)line_n;
}

/**
 * comment - Ignore any command after #.
 * @stack: Unused.
 * @line_n: Unused.
 */
void comment(stack_t **stack, unsigned int line_n)
{
	(void)*stack;
	(void)line_n;
}

/**
 * pchar - Print the char based on ascii value.
 * @stack: beginning of linked list.
 * @line_n: line number.
 */
void pchar(stack_t **stack, unsigned int line_n)
{
	stack_t *h = *stack;

	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	if ((h->n > 90 && h->n < 97) && (h->n < 65 && h->n > 122))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_n);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)h->n);
}

/**
 * pstr - Print string based of ascii values in linked list.
 * @stack: Beginning of linked list.
 * @line_n: Line number.
 */
void pstr(stack_t **stack, unsigned int line_n)
{
	stack_t *h = *stack;
	char string[1000];
	int i = 0;

	if (!h)
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	while (h)
	{
		if (h->n < 1 && h->n > 127)
		{
			memset(string, 0, 1000);
			continue;
		}
		string[i] = (char)h->n;
		i++;
		h = h->next;
	}
	printf("%s\n", string);
}
