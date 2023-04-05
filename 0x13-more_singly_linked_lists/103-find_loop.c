#include "lists.h"

/**
 * find_listint_loop - Finds the loop contained in the list.
 * @head: A pointer to the head.
 * Return: If no loop - NULL.
 *         Otherwise - the address of the node.
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow, *fast;

    if (head == NULL || head->next == NULL)
        return NULL;

    slow = head->next;
    fast = (head->next)->next;

    while (fast)
    {
        if (slow == fast)
        {
            slow = head;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }

        slow = slow->next;
        fast = (fast->next)->next;
    }

    return NULL;
}
