#include "monty.h"

/**
 * exec_loop - Split and execute opcode commands
 * @a: Global struct for buffers.
 */
void exec_loop(buf_struct *a)
{
	stack_t *stack = NULL;
	int line_n = 1, i = 0, check = 0;
	char *status = "stack", *str1;

	while (a->list_cmd[i])
	{
		split_spaces(a->list_cmd[i], a);
		str1 = a->tok_cmd[0];
		if (strcmp(str1, "stack") == 0 || strcmp(str1, "queue") == 0)
			check = 1;
		if (strcmp(str1, "push") == 0)
		{
			if (!a->tok_cmd[1] || digits_only(a->tok_cmd[1]) == 0)
				a->tok_cmd[1] = "r";
			if ((strcmp(a->tok_cmd[1], "0") != 0 && atoi(a->tok_cmd[1]) == 0))
			{
				free_stack(stack);
				fprintf(stderr, "L%d: usage: push integer\n", line_n);
				exit(EXIT_FAILURE);
			}
			else
				push(&stack, atoi(a->tok_cmd[1]));
		}
		else if (check && strcmp(status, str1) != 0)
			queue(&stack, line_n);
		else
		{
			if (get_op_func(str1) == NULL)
			{
				free(stack);
				fprintf(stderr, "L%d: unknown instruction %s\n", line_n, str1);
				exit(EXIT_FAILURE);
			}
			(*get_op_func(str1))(&stack, line_n);
		}
		line_n++;
		i++;
	}
	free_stack(stack);
}

/**
 * get_op_func - selects the correct function to perform
 * @s: name of function
 * Return: pointer to function
 */
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t cmd[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mod", mod},
		{"mul", mul},
		{"nop", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", queue},
		{"stack", queue},
		{NULL, NULL}
	};
	int i = 0;

	while (cmd[i].opcode)
	{
		if (strcmp(s, cmd[i].opcode) == 0)
		{
			return (cmd[i].f);
		}
		i++;
	}
	return (NULL);
}
