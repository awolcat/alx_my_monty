#include "monty.h"
int main(int argc, char *argv[])
{
	char *buffer = NULL, **tokens = NULL, *temp = NULL, *delim = "\t\n ";
	char *piece = NULL;
	int len = 0, i, index;	/*file lengths in bytes*/

	/*Usage: monty file*/
	if (argc == 2)
	{
	buffer = getfile(argv[1]);
	printf("%s\n", buffer);
	/*Get number of lines/commands*/
	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '\n')
			len += 1;
	}
	/*Remove spaces and tabs from file input*/
	temp = malloc(sizeof(char) * 1024);
	if(!temp)
	{
		printf("malloc failed\n");
		return (0);
	}
	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] != '\n' && buffer[i] != '\t')
		{
			temp[index] = buffer[i];
			index++;
		}	
	}
	temp[index] = '\0';
	/*Remove last trailing newline*/
	for (index -= 1; temp[index] != '\0'; index++)
	{
		if (temp[index] == '\n')
		{
			temp[index] = '\0';
			break;
		}
	}
	printf("lines = %d\n", len);
	printf("%s\n", temp);
	/*Tokenize the buffer*/
/*	tokens = token_maker(temp, "\n", &len);*/

	tokens = malloc(sizeof(char *) * len + 1);
	if (!tokens)
	{
		printf("malloc failed\n");
		return (0);
	}
/*	temp = malloc(sizeof(char) * 10);
	for (index = 0; buffer[index] != '\0' && index < len; index++)
	{
		temp = malloc(sizeof(char) * 10);
		while (buffer[i] != '\n')
		{
			temp[i] = buffer[i];
			i++;
			index++;
		}
		temp[i] = '\0';
		tokens[index] = temp;
		free(temp);
		
	}
	*/
	
/*	piece = strtok(temp, delim);
	while (piece != NULL)
	{
		i = strlen(piece);
		printf("%s\n", piece);
		tokens[index] = malloc(sizeof(char) * i);
		strcpy(tokens[index], piece);
		piece = strtok(NULL, delim);
		index++;
	}


	for (i = 0; tokens[i] != NULL; i++)
		printf("%s\n", tokens[i]);	
*/	}
	return (0);
}
	
