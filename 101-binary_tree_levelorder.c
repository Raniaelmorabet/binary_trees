#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of a binary tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * print_level - prints nodes at a given level
 * @tree: pointer to the root node of the tree to traverse
 * @level: level to print
 * @func: pointer to a function to call for each node, value passed as argument
 */
void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;
	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node, value passed as argument
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *node;
	int height, i;

	if (!tree || !func)
		return;
	height = binary_tree_height(tree);
	for (i = 0; i <= height; i++)
	{
		node = (binary_tree_t *)tree;
		print_level(node, i, func);
	}
}
