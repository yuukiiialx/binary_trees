#include "binary_trees.h"
/**
 * bst_search - searches for a node
 * Description: searches for a node in bst
 * @tree: root node
 * @value: the value of the node
 * Return: the found node
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *temp;

	if (tree == NULL)
		return (NULL);
	temp = tree;
	while (temp)
	{
		if (value == temp->n)
		{
			return ((bst_t *)temp);
		}
		if (value > temp->n)
			temp = temp->right;
		else if (value < temp->n)
			temp = temp->left;
	}
	return (NULL);
}
