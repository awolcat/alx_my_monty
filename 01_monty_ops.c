
#include "monty.h"

void pop_stack(stack_t **head, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*head == NULL)
	{
		pop_error(line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*head);
		*head = (*head)->next;
		free(temp);
	}
}

void pint_top(stack_t **head, unsigned int line_number)
{
	if (*head)
	{
		printf("%d\n", (*head)->n);
	}
	else
	{
		pint_error(line_number);
		exit(EXIT_FAILURE);
	}
}

void swap_stack(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int len = 0;

	temp = *head;	
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	if (len < 3)
	{
		swap_error(line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*head)->next;
		(*head)->next = temp->next;
		(temp->next)->prev = *head;
		temp->next = (*head);
		temp->prev = NULL;
		*head = temp;
	}
}

void op_add(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int sum = 0;

	int len = 0;

        temp = *head;
        while (temp)
        {
                len++;
                temp = temp->next;
        }
        if (len < 2)
        {
                add_error(line_number);
                exit(EXIT_FAILURE);
        }
	else
	{
		temp = (*head)->next;
		sum = (*head)->n + temp->n;
		temp = *head;
		*head = (*head)->next;
		(*head)->n = sum;
		free(temp);
	}
}

void nop(stack_t **head __attribute__((unused)), 
		unsigned int line_number __attribute__((unused))){}
