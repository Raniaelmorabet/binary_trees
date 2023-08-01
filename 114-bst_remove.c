#include "binary_trees.h"

/**
 * find_node - finds a node in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node containing a value equals to value, or NULL
 */
bst_t *find_node(bst_t *tree, int value)
{
	bst_t *node = root;

	while (node)
	{
		if (value == node->n)
			return (node);
		else if (value < node->n)
			node = node->left;
		else
			node = node->right;
	}
	return (NULL);
}

/**
 * remove_leaf_node - removes a leaf node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @node: pointer to the node to remove in the tree
 * @parent: pointer to the parent of the node to remove
 * Return: pointer to the new root node of the tree after removing the desired
 */
bst_t *remove_leaf_node(bst_t *root, bst_t *node, bst_t *parent)
{
	if (parent)
	{
		if (parent->left == node)
			parent->left = NULL;
		else
			parent->right = NULL;
	} else
		root = NULL;
	free(node);
	return (root);
}

/**
 * remove_node_with_two_children - removes a node with two children
 * from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @node: pointer to the node to remove in the tree
 * Return: pointer to the new root node of the tree after removing the desired
 */
bst_t *remove_node_with_two_children(bst_t *root, bst_t *node)
{
	bst_t *tmp = node->right;

	while (tmp->left)
		tmp = tmp->left;
	node->n = tmp->n;
	node->right = bst_remove(node->right, tmp->n);
	return (root);
}

/**
 * remove_node_with_one_child - removes a node with one child
 * from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @node: pointer to the node to remove in the tree
 * @parent: pointer to the parent of the node to remove
 * Return: pointer to the new root node of the tree after removing the desired
 */
bst_t *remove_node_with_one_child(bst_t *root, bst_t *node, bst_t *parent)
{
	if (parent)
	{
		if (parent->left == node)
			parent->left = node->left ? node->left : node->right;
		else
			parent->right = node->left ? node->left : node->right;
	} else
		root = node->left ? node->left : node->right;
	if (node->left)
		node->left->parent = parent;
	else
		node->right->parent = parent;
	free(node);
	return (root);
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
	if (!root)
		return (NULL);

	bst_t *parent = NULL;
	bst_t *node = find_node(root, value);

	if (!node)
		return (NULL);

	parent = node->parent;

	if (!node->left && !node->right)
		root = remove_leaf_node(root, node, parent);
	else if (node->left && node->right)
		root = remove_node_with_two_children(root, node);
	else
		root = remove_node_with_one_child(root, node, parent);

	return (root);
}
