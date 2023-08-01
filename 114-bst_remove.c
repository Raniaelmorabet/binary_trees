#include "binary_trees.h"

/**
 * find_node - finds a node in a Binary Search Tree
 * @root: pointer to the root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: pointer to the node containing a value equals to value, or NULL if
 * no node contains value
 */
bst_t *find_node(bst_t *root, int value)
{
	if (!root)
		return (NULL);

	if (root->n == value)
		return (root);
	else if (value < root->n)
		return (find_node(root->left, value));
	else
		return (find_node(root->right, value));
}

/**
 * remove_leaf_node - removes a leaf node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @node: pointer to the node to remove from the tree
 * @parent: pointer to the parent of node
 *
 * Return: pointer to the new root node of the tree after removing the desired
 * value, or NULL on failure
 */
bst_t *remove_leaf_node(bst_t *root, bst_t *node, bst_t *parent)
{
	if (!parent)
		root = NULL;
	else if (node == parent->left)
		parent->left = NULL;
	else
		parent->right = NULL;

	free(node);
	return (root);
}

/**
 * remove_node_with_one_child - removes a node with one child from a Binary
 * Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @node: pointer to the node to remove from the tree
 * @parent: pointer to the parent of node
 *
 * Return: pointer to the new root node of the tree after removing the desired
 * value, or NULL on failure
 */
bst_t *remove_node_with_one_child(bst_t *root, bst_t *node, bst_t *parent)
{
	bst_t *child = NULL;

	if (node->left)
		child = node->left;
	else
		child = node->right;

	if (!parent)
		root = child;
	else if (node == parent->left)
		parent->left = child;
	else
		parent->right = child;

	child->parent = parent;
	free(node);
	return (root);
}

/**
 * remove_node_with_two_children - removes a node with two children from a
 * Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @node: pointer to the node to remove from the tree
 *
 * Return: pointer to the new root node of the tree after removing the desired
 * value, or NULL on failure
 */
bst_t *remove_node_with_two_children(bst_t *root, bst_t *node)
{
	bst_t *successor = NULL;

	successor = node->right;
	while (successor->left)
		successor = successor->left;

	node->n = successor->n;

	if (successor->right)
		root = remove_node_with_one_child(root, successor, successor->parent);
	else
		root = remove_leaf_node(root, successor, successor->parent);

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
