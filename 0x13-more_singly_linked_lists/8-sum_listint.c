#include "lists.h"

/**
 * sum_listint - Calculates the sum of all data (n) of a listint_t list.
 * @head: A pointer to the head.
 * Return: If list is empty - 0.
 *         Otherwise - the sum of all data.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
