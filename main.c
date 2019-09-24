#include "monty.h"
/**
 * make_struct - Set values for struct.
 * @argv: Argument list.
 * Return: Struct for buffers.
 */
buf_struct *make_struct(char *argv[])
{
	static buf_struct a;

	a.argv = argv;
	memset(a.buff, 0, sizeof(a.buff));
	memset(a.buff_array, 0, sizeof(a.buff_array));

	return (&a);
}
/**
 * main - Takes argument list and executes file given.
 * @argc: Argument count.
 * @argv: List of arguments.
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	int fd, bytes;

	a = make_struct(argv);

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if ((fd = open(filename, O_RDWR)) == -1)
	{
		printf("Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	bytes = read(fd, a->buff, 1000);
	split_newline(a);
	exec_loop(a);

	return (0);
}
