#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle in it.
 *
 * @list: pointer to the root of the linked list.
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */

int check_cycle(listint_t *list)
{
	listint_t *a, *b;

	if (list == NULL)
		return (0);

	a = list, b = list;

	while (a->next != NULL && b->next != NULL)
	{
		a = a->next;
		b = b->next->next;

		if (b == NULL)
			break;

		if (a->n == b->n)
			return (1);
	}

	return (0);
}
