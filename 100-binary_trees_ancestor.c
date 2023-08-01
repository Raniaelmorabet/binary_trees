#include "binary_trees.h"

/**
 * binary_tree_is_ancestor - checks if a node is an ancestor of another
 * @node: pointer to the node to check
 * @ancestor: pointer to the ancestor node
 *
 * Return: 1 if node is an ancestor of ancestor, otherwise 0
 */
int binary_tree_is_ancestor(const binary_tree_t *node,
			    const binary_tree_t *ancestor)
{
	if (!ancestor)
		return (0);
	if (node == ancestor)
		return (1);
	return (binary_tree_is_ancestor(node, ancestor->left) ||
		binary_tree_is_ancestor(node, ancestor->right));
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 * or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *ancestor;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	ancestor = (binary_tree_t *)second;
	while (ancestor)
	{
		if (binary_tree_is_ancestor(ancestor, first))
			return (ancestor);
		ancestor = ancestor->parent;
	}
	return (NULL);
}
