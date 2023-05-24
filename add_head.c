#include <stdlib.h>
#include "lists.h"
/**
 * add_dnodeint - add node at beginning of list
 * @head: head of the list
 * @n: data stored in the new node
 *
 * Return: pointer to the new node/head
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->n = n;
	if ((*head) == NULL)
	{
		(*head) = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		(*head)->prev = new;
		new->n = n;
		new->next = *head;
		new->prev = NULL;
		(*head) = new;
	}
	return (new);
}
