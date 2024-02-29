#include "binary_trees.h"
/**
 * _avl_insert - inserts a value in a Balanced Binary Search Tree
 * @array: array containing values
 * @start: start index
 * @end: end index
 * @parent: parent node
 * Return: A pointer to the created node
 *         NULL on failure
 */
avl_t *_avl_insert(int *array, int start, int end, avl_t *parent)
{
	avl_t *root = NULL;
	int i = (start + end) / 2;

	if (start > end)
		return (NULL);
	root = binary_tree_node(parent, array[i]);
	if (root == NULL)
		return (NULL);
	root->right = _avl_insert(array, i + 1, end, root);
	root->left = _avl_insert(array, start, i - 1, root);
	return (root);

}
/**
 * sorted_array_to_avl - creates avl tree from sorted array
 * @array: the array
 * @size: the size of the array
 * Return: root of avl
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);
	root = _avl_insert(array, 0, ((int)size - 1), NULL);
	return (root);

}
