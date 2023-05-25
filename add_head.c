#include "monty.h"

void push_usage_error(int line_no)
{
	char *postfix = ": usage: push integer";
	char *message;
	char num_c[4];
	int len, len2, total;
	int line = line_no;

	len = strlen(postfix);
	for (; line > 0 && len2 < 3; line /= 10)
		num_c[len2++] = (line % 10) + '0';
	num_c[len2++] = '\0';
	total = len + len2;
	message = malloc(sizeof(char) * (total + 1));
	message[0] = 'L';
	for (line = 1, len = 0; num_c[len] != '\0'; line++, len++) 
		message[line] = num_c[len];
	for (len = 0; line <= total; line++, len++)
		message[line] = postfix[len];
	message[line] = '\0';
	write(2, message, total);
	free(message);
}

int check_num(void)
{
	int i, flag = 0;

	for (i = 0; tokens[1][i]; i++)
	{
		if (tokens[1][i] < '0' || tokens[1][i] > '9')
		{
			flag = 1;
			break;
		}
	}
	return (flag);
}
/**
 * add_dnodeint - add node at beginning of list
 * @head: head of the list
 * @n: data stored in the new node
 *
 * Return: pointer to the new node/head
 */
void add_head(stack_t **head, unsigned int line_number)
{
	stack_t *new;
	int n, num_flag;
	
	new = malloc(sizeof(stack_t));
	if (!new)
		exit(EXIT_FAILURE);
	num_flag = check_num();
	if (num_flag == 1 || !tokens[1])
	{
		push_usage_error(line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		n = atoi(tokens[1]);
		new->n = n;
	}
	
	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		(*head)->prev = new;
		new->n = n;
		new->next = *head;
		new->prev = NULL;
		*head = new;
	}
}

