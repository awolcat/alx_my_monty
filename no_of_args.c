#include "monty.h"

/* Get number of args */
int no_of_args(char *str, char *delim, size_t *chars)
{
	int args = 0;
	char * temp = NULL;
	*chars = 0;

	temp = strtok(str, delim);
	while (temp && args < 3)
	{
		args++;
		*chars += strlen(temp);
		temp = strtok(NULL, delim);
	}

	return (args);
}
