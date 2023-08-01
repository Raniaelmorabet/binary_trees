#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *node;

	if (!root || !*root)
		return (0);
	node = *root;
	value = node->n;
	if (!node->left && !node->right)
	{
		*root = NULL;
		free(node);
		return (value);
	}
	node = get_last_node(node);
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;
	(*root)->n = node->n;
	free(node);
	heapify(*root);
	return (value);
}
