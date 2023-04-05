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
	listint_t *ptr1, *ptr2;
	size_t nodecount = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	ptr1 = head->next;
	ptr2 = (head->next)->next;

	while (ptr2)
	{
		if (ptr1 == ptr2)
		{
			ptr1 = head;
			while (ptr1 != hare)
			{
				nodecount++;
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}

			ptr1 = ptr1->next;
			while (ptr1 != ptr2)
			{
				nodecount++;
				ptr1 = ptr1->next;
			}

			return (nodecount);
		}

		ptr1 = ptr1->next;
		ptr2 = (ptr2->next)->next;
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
	size_t nodecount, i;

	nodecount = looped_listint_count(*h);

	if (nodecount == 0)
	{
		for (i=0; h != NULL && *h != NULL; nodes++)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}
	}

	else
	{
		for (i = 0; i < nodecount; i++)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}

		*h = NULL;
	}

	h = NULL;

	return (nodecount);
}
