#include "monty.h"

void print_list(stack_t **head, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;
	
	temp = (*head);
	while(temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
