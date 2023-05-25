
#include "monty.h"

void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
}

void read_error(char *str)
{
	char *prefix = "Error: Can't open file";

	fprintf(stderr, "%s %s\n", prefix, str);
}

void pop_error(int line)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line);
}

void swap_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
}

void add_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
}
