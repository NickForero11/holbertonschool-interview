#include "lists.h"

/**
 * listint_len - Computes the number of elements in a linked listint_t list.
 *
 * @h: the const pointer to the list (it means the HEAD node).
 *
 * Return: the number of nodes(elements) of the list.
 */

size_t listint_len(const listint_t *h)
{
	size_t count;
	const listint_t *iterator;

	count = 0;
	iterator = h;

	while (iterator)
	{
		count++;
		iterator = iterator->next;
	}

	return (count);
}

/**
 * get_nodeint_at_index - Find the nth node of a listint_t linked list.
 *
 * @head: a pointer to the list
 *		  it means a pointer to the HEAD node.
 *
 * @index: the integer that identifies the position of the node in the list.
 *
 * Return: the nth node of a listint_t list or NULL if the node does not exist.
 */

int get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *iterator;
	unsigned int i;

	iterator = head;

	for (i = 0; i < index; i++)
			iterator = iterator->next;

	return (iterator->n);
}

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
	int left, right, end;
	listint_t *iterator;

	if (head == NULL)
		return (1);

	iterator = *head;

	if (iterator == NULL)
		return (1);

	end = listint_len(iterator) - 1;

	while (end > 0)
	{
		left = iterator->n;
		right = get_nodeint_at_index(iterator, end);

		if (left != right)
			return (0);

		iterator = iterator->next;
		end -= 2;
	}

	return (1);
}
