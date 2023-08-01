#include "binary_trees.h"

/**
 * is_complete_tree - Check if a binary tree is complete
 */
int is_complete_tree(const binary_tree_t *tree, int index, int nodes)
{
    if (tree == NULL)
        return 1;

    if (index >= nodes)
        return 0;

    return is_complete_tree(tree->left, 2 * index + 1, nodes) &&
           is_complete_tree(tree->right, 2 * index + 2, nodes);
}

/**
 * is_max_heap - Check if the tree satisfies the max heap property
 */
int is_max_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 1;

    int left_val = (tree->left) ? tree->left->n : tree->n;
    int right_val = (tree->right) ? tree->right->n : tree->n;

    return (tree->n >= left_val && tree->n >= right_val) &&
           is_max_heap(tree->left) && is_max_heap(tree->right);
}

/**
 * binary_tree_is_heap - Check if a binary tree is a valid Max Binary Heap
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    int node_count = binary_tree_size(tree);
    return is_complete_tree(tree, 0, node_count) && is_max_heap(tree);
}
