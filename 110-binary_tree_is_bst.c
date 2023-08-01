#include "binary_trees.h"

/**
 * binary_tree_is_bst_helper - checks if a binary tree is a
 * valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (binary_tree_is_bst_helper(tree->left, min, tree->n - 1) &&
		binary_tree_is_bst_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_is_bst_helper(tree, INT_MIN, INT_MAX));
}
