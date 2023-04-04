#include "lists.h"

/**
 * get_nodeint_at_index - Locates a given node of
 *                        a listint_t linked list.
 * @head: A pointer to the head.
 * @index: The index of the node - start at 0.
 * Return: If node does not exist - NULL.
 *         Otherwise - located node.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int nod;

	for (nod = 0; nod < index; nod++)
	{
		if (head == NULL)
			return (NULL);

		head = head->next;
	}

	return (head);
}
