#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate node to the right
 * Description: the movement of the node to down to the right
 * @tree: root node to move
 * Return: nothing
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *parent;

	if (tree == NULL)
		return (NULL);
	parent = tree->parent;

	tree->left->parent = parent;
	if (parent != NULL)
	{
		if (parent->right == tree)
			parent->right = tree->left;
		else
			parent->left = tree->left;
	}
	tree->parent = tree->left;
	tree->left = tree->parent->right;
	if (tree->left != NULL)
		tree->left->parent = tree;
	tree->parent->right = tree;
	return (tree->parent);
}
