#include "monty.h"

/* Get number of args */
int no_of_args(char *str)
{
	int len = 0;
	int i;

        for (i = 0; str[i] != '\0'; i++)
        {
                if (((str[i] >= 'a' && str[i] < 'z') ||
			(str[i] >= '0' && str[i] <= '9')) && 
			(str[i + 1] == ' ' || str[i + 1] == '\t'))
                        len += 1;
        }
	return (len);
}
