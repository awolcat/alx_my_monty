
#include "monty.h"

void usage_error(void)
{
	write(2, "USAGE: monty fiile", 1024);
}

void read_error(char *str)
{
	int len;
	int len2;
	char *message;
	char *prefix = "Error: Can't open file ";

	len = strlen(str) + 1;
	len2 = strlen(prefix);
	message = malloc(sizeof(char) * (len + len2));
	for (len = 0; prefix[len] != '\0'; len++)
		message[len] = prefix[len];
	for (len2 = 0; str[len2] != '\0'; len2++, len++)
	       message[len] = str[len2];
	message[len] = '\0';
	write(2, message, 1024);
	free(message);
}
