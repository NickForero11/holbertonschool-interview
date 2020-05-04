#include "binary_trees.h"

/**
 * binary_tree_is_full	-	Checks if a tree is full binary tree
 *							(Every node has 2 childrens).
 *
 * @tree: The pointer of the tree that will be checked.
 *
 * Return: 1 if tree is a full binary tree otherwise 0.
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else if (tree->right != NULL && tree->left != NULL)
		return (1);
	else
		return (0);
}

/**
 * heap_insert_correct_level	-	Inserts a node in a binary tree according
 *									the current level if the tree isn't full.
 *
 * @root: The pointer to the tree where the node will be inserted.
 *
 * @new_node: The new node that will be inserted.
 *
 * Return:	A pointer to the inserted node, otherwise
 *			NULL if it fails or the tree is full.
*/

heap_t *heap_insert_correct_level(heap_t **root, heap_t *new_node)
{
	heap_t *iterator;

	iterator = *root;

	if (new_node == NULL)
		return (NULL);

	/*Case root is full*/
	if (binary_tree_is_full(iterator))
	{
		/*case left node is full*/
		if (binary_tree_is_full(iterator->left))
		{
			/*Case left and right node are full*/
			if (binary_tree_is_full(iterator->right))
				return (NULL);
			/*Case left is full but right not*/
			heap_insert_correct_level(&(iterator->right), new_node);
		}
		/*Case left isn't full*/
		else
			heap_insert_correct_level(&(iterator->left), new_node);
	}
	/*Case root not full*/
	else
	{
		new_node->parent = iterator;
		if (iterator->left == NULL)
			iterator->left = new_node;
		else
			iterator->right = new_node;
	}

	return (new_node);
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
	heap_t *response;

	if (new_node == NULL)
		return (NULL);

	/*Try to insert the new node in the current level*/
	response = heap_insert_correct_level(root, new_node);

	/*Case childrens are full*/
	if (response == NULL)
	{
		/*Try insert on the left node*/
		response = heap_insert_driver(&((*root)->left), new_node);
		/*Try insert on the right node*/
		if (response == NULL)
			response = heap_insert_driver(&(*root)->right, new_node);
	}

	return (response);
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
