#include "binary_trees.h"
/**
 * binary_tree_height - gets the height
 * Description: a function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree
 * Return: height or 0 if tress is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		height_left = 1 + binary_tree_height(tree->left);
	if (tree->right != NULL)
		height_right = 1 + binary_tree_height(tree->right);
	if (height_left > height_right)
		return (height_left);
	return (height_right);
}
