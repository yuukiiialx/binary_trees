#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate node to the left
 * Description: the movement of the node to down to the left
 * @tree: root node to move
 * Return: nothing
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *parent;

	if (tree == NULL)
		return (NULL);
	parent = tree->parent;

	if (parent != NULL && parent->left == tree)
	{
		parent->left = tree->right;
		tree->right->parent = parent;
		tree->right = tree->right->left;
		if (tree->right)
			tree->right->parent = tree;
		tree->parent = parent->left;
		parent->left->left =  tree;
	}
	else if (parent != NULL)
	{
		parent->right = tree->right;
		tree->right->parent = parent;
		tree->right = tree->right->left;
		if (tree->right)
			tree->right->parent = tree;
		tree->parent = parent->right;
		parent->right->left =  tree;
	}
	else
	{
		tree->parent = tree->right;
		tree->right->parent = parent;
		tree->right = tree->right->left;
		if (tree->right)
			tree->right->parent = tree;
		tree->parent->left = tree;
	}
	return (tree->parent);
}
