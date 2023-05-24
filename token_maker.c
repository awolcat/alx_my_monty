#include "monty.h"

/**
 * word_split - splits a string into tokens
 * @str: a string
 * @delim: delimeter for splitting the string
 *
 * Return: An array of pointers if successful, NULL otherwise
 */

char **token_maker(char *str, char *delim, int *line_count)
{
	char **new = NULL;
	int i = 0;
	char *tmp = NULL;
	int len = *line_count;
	char *copy;

	copy = strdup(str);
	printf("%s\n", str);
        /*Tokenize the buffer*/
	new = malloc(sizeof(char *) * len);
	if (!new)
		return (NULL);
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
