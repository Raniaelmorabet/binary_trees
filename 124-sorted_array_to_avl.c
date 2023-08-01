#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree for
 * inserting the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node, *parent;

	if (!tree)
		return (NULL);
	parent = NULL;
	node = *tree;
	while (node)
	{
		parent = node;
		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
		else
			return (NULL);
	}
	node = binary_tree_node(parent, value);
	if (!node)
		return (NULL);
	if (!parent)
		*tree = node;
	else if (value < parent->n)
		parent->left = node;
	else
		parent->right = node;
	return (node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i;

	for (i = 0; i < size; i++)
		avl_insert(&tree, array[i]);
	return (tree);
}
