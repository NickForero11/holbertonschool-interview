#include "lists.h"
/**
 * insert_node - Adds a new node into a sorted linked list.
 *
 * @head: a pointer to the head node of the list.
 *
 * @number: the data(an integer number) that will be saved in the new node.
 *
 * Return: the address of the new element, or NULL if it failed.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *iterator;
	listint_t *new_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		iterator = *head;

		if (iterator->n < number)
		{
			while (iterator->next != NULL && number > iterator->next->n)
				iterator = iterator->next;

			new_node->next = iterator->next;
			iterator->next = new_node;
		} else
		{
			new_node->next = iterator;
			*head = new_node;
		}
	}

	return (new_node);
}
