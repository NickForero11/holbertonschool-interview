#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: The pointer of the tree that will be measured.
 *
 * Return: The height of the tree as a size_t value.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_height >= right_height ? left_height : right_height);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: The pointer of the tree that will be measured.
 *
 * Return: The size of the tree as a size_t value.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a tree is a perfect binary tree
 *							(where number of nodes is equal to (2^height) - 1).
 *
 * @tree: The pointer of the tree that will be checked.
 *
 * Return: 1 if tree is a perfect binary tree otherwise 0.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, perfect, size;

	if (tree == NULL)
	{
		return (0);
	}

	height = binary_tree_height(tree);
	perfect = ((2 << height) - 1);
	size = binary_tree_size(tree);

	return (perfect == size ? 1 : 0);
}

/**
 * heap_insert_driver	-	Inserts a node in a binary tree according
 *							the current level taking in account
 *							if the tree is full or not.
 *
 * @root: The pointer to the tree where the node will be inserted.
 *
 * @new_node: The new node that will be inserted.
 *
 * Return:	A pointer to the inserted node, otherwise NULL if it fails.
*/

heap_t *heap_insert_driver(heap_t **root, heap_t *new_node)
{
	heap_t *iterator;

	if (new_node == NULL)
		return (NULL);

	iterator = *root;
	/*Case root is full*/
	if (!(iterator->right != NULL && iterator->left != NULL))
	{
		new_node->parent = iterator;
		if (iterator->left == NULL)
			iterator->left = new_node;
		else
			iterator->right = new_node;
		return (new_node);
	}
	/*Case root not perfect*/
	else if (!binary_tree_is_perfect(iterator))
	{
		/*Check the children nodes and add the new node to the imperfect node*/
		if (!binary_tree_is_perfect(iterator->left))
		{
			heap_insert_driver(&(iterator->left), new_node);
		}
		else
		{
			heap_insert_driver(&(iterator->right), new_node);
		}
		return (new_node);
	}
	else
	/*Case root full, insert in the left node to make it imperfect*/
	{
		heap_insert_driver(&(iterator->left), new_node);
		return (new_node);
	}
	return (NULL);
}

/**
 * heapify	-	Guarantee that every node in the tree follows
 *				the max heap property changing the nodes if it's needed.
 *
 * @root: The pointer to the node that will be checked.
 *
 * Return:	A pointer to the checked node, otherwise NULL if it fails.
*/

heap_t *heapify(heap_t **root)
{
	int parent_value;
	heap_t *copy_root, *parent;

	/*First check if the root node its valid*/
	if (root != NULL)
	{
		copy_root = *root;
		if (copy_root != NULL)
		{
			/*Check if the root node has parents*/
			parent = copy_root->parent;
			/*
			 *If it has parents check if it needs to be reordered to follow
			 *the max heap property
			*/
			if (parent != NULL)
			{
				if (copy_root->n > parent->n)
				{
					/*Change the parent with the children node*/
					parent_value = parent->n;
					parent->n = copy_root->n;
					copy_root->n = parent_value;
					*root = parent;
					/*Check the parent node*/
					heapify(root);
				}
			}
		}
	}

	return (*root);
}

/**
 * heap_insert	-	Inserts a node in a Max binary heap.
 *
 * @root: The pointer to the tree where the node will be inserted.
 *
 * @value: The value of the new node that will be inserted.
 *
 * Return:	A pointer to the inserted node, otherwise NULL if it fails.
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *response;

	if (root == NULL)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	/*Case empty tree*/
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	/*Insert into tree according the level*/
	response = heap_insert_driver(root, new_node);
	/*Heapify the new node and it's parents to preserve the max heap property*/
	response = heapify(&response);

	return (response);
}
