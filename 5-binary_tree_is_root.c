#include "binary_trees.h"
/**
 * binary_tree_is_root - checks if node is root
 * Description: checks if node has a parent
 * @node: pointer to the node to check
 * Return: 1 if root, 0 if not
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node != NULL && node->parent == NULL)
		return (1);
	return (0);
}
