
#include "monty.h"

void free_stack(stack_t **head)
{
	stack_t *temp;

	while (*head != NULL)
	{
		temp = (*head)->next;

		free(*head);

		(*head) = temp;
	}
}

void free_grid(char **grid)
{
	int i = 0;

	while (grid[i] != NULL)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
