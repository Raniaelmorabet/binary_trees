#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node containing a value equals to value, or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing the desired
 * value, or NULL on failure
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *parent, *tmp;

	node = bst_search(root, value);
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
			tmp->parent->left = bst_remove(tmp, tmp->n);
		else
			tmp->parent->right = bst_remove(tmp, tmp->n);
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
