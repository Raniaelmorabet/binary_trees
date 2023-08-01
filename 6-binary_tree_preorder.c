#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 * 	  The value in the node must be passed as a parameter to this function.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	/* If tree or func is NULL, do nothing */
	if (tree == NULL || func == NULL)
		return;

	/* Call func on value in tree */
	func(tree->n);

	/* If tree has a left child, traverse left subtree */
	if (tree->left != NULL)
		binary_tree_preorder(tree->left, func);

	/* If tree has a right child, traverse right subtree */
	if (tree->right != NULL)
		binary_tree_preorder(tree->right, func);
}
