#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary tree node.
 *
 * @parent: The parent (or father) node of the new node.
 *
 * @value: The data inside the new node.
 *
 * Return: A pointer to the new binary tree node
 *         NULL otherwise.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
	{
		return (NULL);
	}

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
