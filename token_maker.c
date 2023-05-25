#include "monty.h"

/**
 * word_split - splits a string into tokens
 * @str: a string
 * @delim: delimeter for splitting the string
 *
 * Return: An array of pointers if successful, NULL otherwise
 */

char **token_maker(char *str, char *delim, int *arg_count)
{
	char **new = NULL;
	int i = 0;
	char *tmp = NULL;
	char *copy;

	copy = strdup(str);
	new = malloc(sizeof(char *) * (*arg_count + 1));
	if (!new)
		exit(EXIT_FAILURE);
	tmp = strtok(copy, delim);
	while (tmp != NULL)
	{
		new[i] = tmp;
		tmp = strtok(NULL, delim);
		i++;
	}
	new[i] = NULL;
	return (new);
}
