#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
		size = 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
	return (size);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array of
 * integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: pointer to a newly allocated array containing the sorted values, or
*/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array, *tmp;
	size_t i, s;

	if (!heap || !size)
		return (NULL);
	s = binary_tree_size(heap);
	array = malloc(sizeof(int) * s);
	if (!array)
		return (NULL);
	for (i = 0; i < s; i++)
	{
		array[i] = heap->n;
		tmp = &heap->n;
		while (heap->left || heap->right)
		{
			if (!heap->right || heap->left->n > heap->right->n)
			{
				*tmp = heap->left->n;
				tmp = &heap->left->n;
				heap = heap->left;
			}
			else if (!heap->left || heap->left->n < heap->right->n)
			{
				*tmp = heap->right->n;
				tmp = &heap->right->n;
				heap = heap->right;
			}
		}
		*tmp = heap->n;
		heap = heap->parent;
	}
	*size = s;
	return (array);
}
