#include "monty.h"

/*Get number of lines/commands*/
int no_of_lines(char *str)
{
	int len = 0;
	int i;

        for (i = 0; str[i] != '\0'; i++)
        {
                if (str[i] == '\n')
                        len += 1;
        }
	return (len);
}
