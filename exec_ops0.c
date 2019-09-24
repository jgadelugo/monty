#include "monty.h"

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

