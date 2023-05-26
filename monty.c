#include "monty.h"

char **tokens;

int main(int argc, char	*argv[])
{
	FILE *stream;
	char *buffer = NULL;
	char *delim = " \n\t";
	char *copy;
	int arg_count, j;
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
		copy = strdup(buffer);
		arg_count = no_of_args(buffer, delim, &line_size);
		/*Tokenize the line*/
		tokens = token_maker(copy, delim, &arg_count, &line_size);
		/* Match arg to funct */
		if (arg_count > 0)
		{
			for (j = 0; commands[j].opcode != NULL; j++)
			{
				if (strcmp(commands[j].opcode, tokens[0]) == 0)
				{
					(commands[j].f)(&head, line_no);
					free_grid(tokens);
					break;
				}
			}
			if (commands[j].opcode == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_no, tokens[0]);
				fclose(stream);
				free(copy);
				free_stack(&head);
				free(buffer);
				free_grid(tokens);
				exit(EXIT_FAILURE);
			}
		}
		free(copy);
	}
	fclose(stream);
	free_stack(&head);
	free(buffer);
	return (0);
}	
