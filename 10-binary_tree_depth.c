#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @node: pointer to the node to measure the depth
 *
 * Return: depth of the node, or 0 if node is NULL
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t depth = 0;

	if (node == NULL)
		return (0);

	/* Traverse up the tree */
	while (node->parent != NULL)
	{
		node = node->parent;
		depth++;
	}

	return (depth);
}
