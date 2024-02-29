#include "binary_trees.h"
/**
 * binary_tree_postorder - traverses tree in postorder sequence
 * Description: traverses the left->right->root
 *              and sends the value of the node to a function
 * @tree: pointer to the root
 * @func: pointer to a function to call for each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
