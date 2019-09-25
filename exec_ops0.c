#include "monty.h"

void exec_loop(buf_struct *a)
{
	stack_t *stack = NULL;
	int line_n = 1, i = 0;
	
        while (a->list_cmd[i])
        {
		split_spaces(a->list_cmd[i], a);
		if (strcmp(a->tok_cmd[0], "push") == 0)
		{
			push(&stack, atoi(a->tok_cmd[1]), line_n);
			line_n++;
		}
		else
		{
			if (get_op_func(a->tok_cmd[0]) == NULL)
			{
				i++;
				continue;
			}
			(*get_op_func(a->tok_cmd[0]))(&stack, line_n);
			line_n++;
		}
		i++;
	}
}

/**
 * get_op_func - selects the correct function to perform
 * @s: name of function
 * @n: value of n
 * Return: pointer to function
 */
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t cmd[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
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
