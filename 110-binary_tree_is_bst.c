#include "binary_trees.h"
/**
 * check_less - checks if all nodes are less
 * Description: makes sure that all nodes
 *              are less than n
 * @tree: pointer to the root
 * @n: number to compare
 * Return: 1 if more 0 if not
 */
int check_less(const binary_tree_t *tree, int n)
{
	if (tree == NULL)
		return (1);
	if (tree->n >= n)
		return (0);
	return (check_less(tree->left, n) * check_less(tree->right, n));
}
/**
 * check_more - checks if all nodes are more
 * Description: makes sure that all nodes
 *              are more than n
 * @tree: pointer to the root
 * @n: number to compare
 * Return: 1 if more 0 if not
 */
int check_more(const binary_tree_t *tree, int n)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= n)
		return (0);
	return (check_more(tree->left, n) * check_more(tree->right, n));
}
/**
 * validate_bst - validates the tree
 * Description: makes sure that all nodes
 *              on the left are less and all nodes
 *              on the right are more
 * @tree: pointer to the root
 * Return: 1 if validated 0 if not
 */
int validate_bst(const binary_tree_t *tree)
{
	int r1, r2, r3, r4;

	if (tree == NULL)
		return (1);
	r1 = check_less(tree->left, tree->n);
	r2 = check_more(tree->right, tree->n);
	r3 = validate_bst(tree->left);
	r4 = validate_bst(tree->right);
	return (r1 * r2 * r3 * r4);
}
/**
 * binary_tree_is_bst - checks if tree is bst
 * Description: checks if bst by calling the validate func
 * @tree: pointer to the root
 * Return: 1 if bst 0 if not or NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (validate_bst(tree));
}
