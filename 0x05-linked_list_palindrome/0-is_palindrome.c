#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 *
 * @head: the pointer to the starpoint of the list (it means the HEAD node).
 *
 * Return:	0 if it is not a palindrome, 1 if it is a palindrome, also
 *			an empty list is considered a palindrome.
 */

int is_palindrome(listint_t **head)
{
	int start, end;
	int array[500];
	listint_t *iterator;

	if (head == NULL)
		return (1);

	iterator = *head;

	if (iterator == NULL)
		return (1);

	start = 0;

	for (end = 0; iterator != NULL; end++)
	{
		array[end] = iterator->n;
		iterator = iterator->next;
	}

	end--;

	while (start <= end)
	{
		if (array[start] != array[end])
			return (0);
		start++;
		end--;
	}

	return (1);
}
