#include "monty.h"

char **tokens;

int main(int argc, char	*argv[])
{
	FILE *stream;
	char *buffer = NULL;
	char *delim = " \n\t";
	char *copy;
	int arg_count, j, i;
	unsigned int line_no = 0;
	stack_t *head = NULL;
	size_t line_size;
	
	instruction_t commands[] = {
		{"push", add_head},
		{"pall", print_list},
		{"pop", pop_stack},
		{"pint", pint_top},
		{"swap", swap_stack},
		{"add", op_add},
		{"nop", nop},
		{NULL, NULL}
	};
	
	if (argc != 2)
	{
		usage_error();
		exit(EXIT_FAILURE);	
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		read_error(argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &line_size, stream) != - 1)
	{
		line_no += 1;
		arg_count = no_of_args(buffer);
		copy = malloc(sizeof(char) * line_size + 1);
		/*Tokenize the line*/
		strcpy(copy, buffer);
		tokens = token_maker(copy, delim, &arg_count);
		/* Free redundant buffer
		free(buffer);*/
		/* Match arg to funct */
		for (j = 0; commands[j].opcode != NULL; j++)
		{
			for (i = 0; tokens[i] != NULL; i++)
			{
				if (strcmp(commands[j].opcode, tokens[i]) == 0)
				{
					(commands[j].f)(&head, line_no);
					break;
				}
			}
		}

	}
	fclose(stream);
	free_stack(&head);
/*	free_grid(tokens);
*/	return (0);
}	
