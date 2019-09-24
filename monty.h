#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct buf_struct - Global buffers.
 * @buff: Buffer for read.
 * @buff_array: Tokenized read buffer.
 * @argv: Arguments from command line.
 *
 * Description: - Buffers used globally throughout files.
 */
typedef struct buf_struct
{
	char buff[1000];
	char *buff_array[1000];
	char **argv;
} buf_struct;

/* monty functions */

stack_t *push(stack_t **head, int n);
size_t pall(stack_t *h);
void pint(stack_t *h);

/* end of monty functions */

#endif /*MONTY_H*/
