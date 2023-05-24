#include "monty.h"

char *getfile(char* file)
{
	FILE *stream;
	char c;
	char *buffer = NULL;
	int len = 0, i = 0;

	stream = fopen(file, "r");
	/*Count number of chars or file len*/
	for (c = getc(stream), len = 0; c != EOF; c = getc(stream), len++)
		;
	/*Copy string to local buffer*/
	fseek(stream, 0, SEEK_SET);
	buffer = malloc(sizeof(c) * len + 1);
	for (i = 0, c = fgetc(stream); c != EOF; c = fgetc(stream), i++)
		buffer[i] = c;
	fclose(stream);
	buffer[i] = '\0';
	return (buffer);
}
