#include "binary_trees.h"
/**
 * binary_tree_preorder - traverses tree in preorder sequence
 * Description: traverses the root->left->right
 *              and sends the value of the node to a function
 * @tree: pointer to the root
 * @func: pointer to a function to call for each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
