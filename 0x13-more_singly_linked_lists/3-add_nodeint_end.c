#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: A pointer to the address
 * @n: The integer for the new node
 * Return: If function fails - NULL.
 * 	    Otherwise - the address of the new element
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *add, *last;

	add = malloc(sizeof(listint_t));
	if (add == NULL)
		return (NULL);

	add->n = n;
	add->next = NULL;

	if (*head == NULL)
		*head = add;

	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = add;
	}

	return (*head);
}
