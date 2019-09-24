#include "monty.h"

/**
 * get_op_func - selects the correct function to perform
 * @s: name of function
 * @n: value of n
 * Return: pointer to function
 */
int (*get_op_func(char *s, int n))(int n)
{
	instruction_t cmd[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	int i = 0;

	while (cmd[i].op)
	{
		if (strcmp(s, cmd[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL)
}
