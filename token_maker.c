#include "monty.h"

/**
 * word_split - splits a string into tokens
 * @str: a string
 * @delim: delimeter for splitting the string
 *
 * Return: An array of pointers if successful, NULL otherwise
 */

char **token_maker(char *str, char *delim __attribute__((unused)), int *arg_count, size_t *chars)
{
	char **new = NULL;
	int i, j, len1 = 0;
	char *copy = NULL, *arg_0 = NULL, *arg_1 = NULL;

	copy = malloc(sizeof(char) * ((*chars) + 2));
	for (i = 0, j = 0; str[i] != '\n'; i++)
	{
		if ((str[i] > 96 && str[i] < 123) || 
		(str[i] > 47 && str[i] < 58) ||
		(str[i] == ' ' && str[i + 1] > 47 && str[i + 1] < 58))
		{
			copy[j] = str[i];
			j++;
		}
	}
	copy[j] = '\0';
	new = malloc(sizeof(char *) * (*arg_count + 1));
	if (!new)
		exit(EXIT_FAILURE);
	/* Isolate arg_0 */
	for (j = 0; copy[j] != '\0' && copy[j] != ' '; j++)
		;
	len1 = j;
	arg_0 = malloc(sizeof(char) * (len1 + 1));
	for (j = 0; copy[j] != '\0' && copy[j] != ' '; j++)
		arg_0[j] = copy[j];
	arg_0[j] = '\0';
	new[0] = arg_0;
	/* Isolate arg_1 */
	len1 += 1;
	j += 1;
	if ((*arg_count) == 2)
	{
		for (i = 0; copy[len1] != '\0'; len1++, i++)
		       ;
		arg_1 = malloc(sizeof(char) * (i + 1));
		for (i = 0; copy[j] != '\0'; j++, i++)
		{
			arg_1[i] = copy[j];
		}
		arg_1[i] = '\0';
		new[1] = arg_1;
		new[2] = NULL;
	}
	else if ((*arg_count) < 2)
		new[1] = NULL;
	free(copy);
	return (new);
}
