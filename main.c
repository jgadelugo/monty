#include "monty.h"
/**
 *
 *
 */
int main(int argc, char *argv[])
{
	int fd, bytes;
	char buff[1000], *buff_array[];

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

	bytes = read(fd, buff, 1000);
	_split(buff, buff_array);
	main_loop(buff);

}
