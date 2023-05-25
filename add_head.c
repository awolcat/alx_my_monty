#include "monty.h"

void push_usage_error(int line_no)
{
	char *postfix = ": usage: push integer\n";
	int len;

	len = strlen(postfix);
	write(2, "L", 1);
	write(2, &line_no, 5);	
	write(2, postfix, len);
}

int check_num(void)
{
	int i, flag = 0;
	
	if (tokens[1] != NULL)
	{
		for (i = 0; tokens[1][i]; i++)
		{
			if (tokens[1][i] < '0' || tokens[1][i] > '9')
			{
				flag = 1;
				break;
			}
		}
	}
	else
		flag = 1;
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
	if (num_flag == 1)
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

