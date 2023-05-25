#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* GLOBAL VARIABLE */
extern char **tokens;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* HELPER FUNCTIONS */

char **token_maker(char *str, char *delim, int*);
int no_of_args(char *str);
int check_num(void);
void read_error(char *str);
void usage_error(void);

/* OPCODE FUNCTIONS */
void add_head(stack_t **head, unsigned int line_number);
void print_list(stack_t **head, unsigned int line_number __attribute__((unused)));
void pop_stack(stack_t **head, unsigned int line_number);

/* OPCODE ERRORS */
void push_usage_error(int line_no);
void pop_error(int line);
#endif
