#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	/* Base case */
	if (tree == NULL)
		return (0);

	/* Compute the height of each subtree */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* Return the larger one */
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
