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

	a = list;

	if (a->next == NULL)
		return (0);

	b = a->next;

	while (b->next != NULL)
	{
		if (a->n == b->n)
			return (1);

		a = a->next;

		if (b->next == NULL)
			break;

		b = b->next->next;

	}

	return (0);
}
