#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	listint_t *head;

	head = NULL;
	insert_node(&head, 1);
	insert_node(&head, 402);
	insert_node(&head, 4);
	insert_node(&head, 1024);
	insert_node(&head, 0);
	insert_node(&head, 98);
	insert_node(&head, 2);
	insert_node(&head, 3);
	print_listint(head);

	printf("-----------------\n");

	insert_node(&head, 102492);
	insert_node(&head, -1);

	print_listint(head);

	free_listint(head);

	return (0);
}
