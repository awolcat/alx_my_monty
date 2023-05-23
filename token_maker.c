#include "monty.h"

/**
 * word_split - splits a string into tokens
 * @str: a string
 * @delim: delimeter for splitting the string
 *
 * Return: An array of pointers if successful, NULL otherwise
 */

char **token_maker(char *str, char *delim, int *len)
{
	char **new = NULL;
	int i = 0;
	char *tmp = NULL;
	int length = *len;

	new = malloc(sizeof(char *) * length);
	if (!new)
		return (NULL);

	tmp = strtok(str, delim);
	while (tmp != NULL)
	{
		length = strlen(tmp);
		new[i] = malloc(sizeof(char) * length);
		new[i] = strdup(tmp);
		tmp = strtok(NULL, delim);
		i++;
	}
	new[i] = tmp;
	for (i = 0; new[i] != NULL; i++)
		printf("%s\n", new[i]);

	return (new);
}
