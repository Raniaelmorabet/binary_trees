#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the nodes in
 *
 * Return: number of nodes with at least 1 child in a binary tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		if (tree->left || tree->right)
			nodes++;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (nodes);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nodes = 0, i = 0;
	int flag = 0;
	binary_tree_t **queue = NULL;

	if (!tree)
		return (0);
	nodes = binary_tree_nodes(tree);
	queue = malloc(sizeof(binary_tree_t *) * (nodes + 1));
	if (!queue)
		return (0);
	queue[0] = (binary_tree_t *)tree;
	while (i <= nodes)
	{
		if (queue[i]->left)
		{
			if (flag)
			{
				free(queue);
				return (0);
			}
			queue[2 * i + 1] = queue[i]->left;
		}
		else
			flag = 1;
		if (queue[i]->right)
		{
			if (flag)
			{
				free(queue);
				return (0);
			}
			queue[2 * i + 2] = queue[i]->right;
		}
		else
			flag = 1;
		i++;
	}
	free(queue);
	return (1);
}
