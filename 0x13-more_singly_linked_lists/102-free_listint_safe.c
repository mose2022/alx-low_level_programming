#include "lists.h"

size_t looped_listint_count(listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * looped_listint_count - Counts number of unique nodes.
 * @head: A pointer to the head.
 * Return: If list is not looped - 0.
 *         Otherwise - number of unique nodes.
 */
size_t looped_listint_count(listint_t *head)
{
	listint_t *torte, *ha;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	tort = head->next;
	ha = (head->next)->next;

	while (ha)
	{
		if (torte == hare)
		{
			torte = head;
			while (torte != ha)
			{
				nodes++;
				torte = torte->next;
				ha = ha->next;
			}

			torte = torte->next;
			while (torte != ha)
			{
				nodes++;
				torte = torte->next;
			}

			return (nodes);
		}

		torte = torte->next;
		ha = (ha->next)->next;
	}

	return (0);
}

/**
 * free_listint_safe - Frees a listint_t list safely
 * @h: A pointer to the address of the head.
 * Return: Size of list that was freed.
 * Description: Function sets head to NULL.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp;
	size_t nodes, index;

	nodes = looped_listint_count(*h);

	if (nodes == 0)
	{
		for (; h != NULL && *h != NULL; nodes++)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}

		*h = NULL;
	}

	h = NULL;

	return (nodes);
}
