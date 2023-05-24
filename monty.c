#include "monty.h"
int main(int argc, char *argv[])
{
	char *buffer = NULL, **tokens = NULL;
	char *delim = " \n\t";
	char copy[1024];
	int i, line_count;	/*file lengths in bytes*/
	stack_t **head;
	unsigned int line = 0;
	
	instruction_t commands[] = {
		{"push", add_head},
		{"pall", print_list},
		{NULL, NULL}
	}

	/*Usage: monty file*/
	if (argc == 2)
	{
		buffer = getfile(argv[1]);
		/*Tokenize the buffer*/
		strcpy(copy, buffer);
		line_count = no_of_lines(buffer);
		tokens = token_maker(copy, delim, &line_count);
		/*Match arg to funct*/
		for (j = 0; commands[j].opcode != NULL; j++)
		{
			for (i = 0; tokens[i] != NULL; i++)
			{
				if (strcmp(commands[j].opcode, tokens[i]) == 0)
					(commands[j].f)(head, ++line);
			}
		}


	}
	return (0);
}
	
