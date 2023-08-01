#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left = NULL;

	/* If parent is NULL, return NULL */
	if (parent == NULL)
		return (NULL);

	/* Allocate memory for new node */
	new_left = malloc(sizeof(binary_tree_t));
	if (new_left == NULL)
		return (NULL);

	/* Initialize new node */
	new_left->n = value;
	new_left->parent = parent;
	new_left->left = NULL;
	new_left->right = NULL;

	/* If parent has a left child, set new node as left child */
	if (parent->left != NULL)
	{
		new_left->left = parent->left;
		new_left->left->parent = new_left;
	}
	/* Set new node as left child of parent */
	parent->left = new_left;

	/* Return new node */
	return (new_left);
}
