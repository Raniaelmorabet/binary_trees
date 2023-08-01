#include "binary_trees.h"

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing the desired
 * value, or NULL on failure
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node, *parent, *tmp;

	if (!root)
		return (NULL);
	node = root;
	parent = NULL;
	while (node)
	{
		if (value == node->n)
			break;
		parent = node;
		if (value < node->n)
			node = node->left;
		else
			node = node->right;
	}
	if (!node)
		return (root);
	if (!node->left && !node->right)
	{
		if (parent)
		{
			if (parent->left == node)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else
			root = NULL;
		free(node);
	}
	else if (node->left && node->right)
	{
		tmp = node->right;
		while (tmp->left)
			tmp = tmp->left;
		node->n = tmp->n;
		if (tmp->parent->left == tmp)
			tmp->parent->left = avl_remove(tmp, tmp->n);
		else
			tmp->parent->right = avl_remove(tmp, tmp->n);
	}
	else
	{
		if (parent)
		{
			if (parent->left == node)
				parent->left = node->left ? node->left : node->right;
			else
				parent->right = node->left ? node->left : node->right;
		}
		else
			root = node->left ? node->left : node->right;
		if (node->left)
			node->left->parent = parent;
		else
			node->right->parent = parent;
		free(node);
	}
	return (root);
}
