#include "binary_trees.h"
/**
 * swap - swaps two nodes
 * Description: swaps a node with its child
 * @root: root node of the tree
 * @child: child of the node
 * @temp: temp to swap
 */
void swap(bst_t *temp, bst_t *child, bst_t **root)
{

	if (temp->parent == NULL)
	{
		child->parent = NULL;
		(*root) = child;
		free(temp);
	}
	else
	{
		if (temp->parent->right == temp)
			temp->parent->right = child;
		else
			temp->parent->left = child;
		child->parent = temp->parent;
		free(temp);
	}
}
/**
 * swap_with_successor - swaps two nodes
 * Description: swaps a node with its in-order successor
 * @root: root node of the tree
 * @temp: temp to swap
 */
void swap_with_successor(bst_t *temp, bst_t **root)
{
	bst_t *temp2, *old_parent, *old_right;

	temp2 = temp->right;
	while (temp2->left)
		temp2 = temp2->left;
	old_parent = temp2->parent;
	temp2->parent = temp->parent;
	if (temp2->parent == NULL)
		(*root) = temp2;
	else if (temp2->parent->right == temp)
		temp2->parent->right = temp2;
	else
		temp2->parent->left = temp2;
	temp2->left = temp->left;
	temp2->left->parent = temp2;
	old_right = temp2->right;
	temp2->right = (old_parent != temp) ? temp->right : temp2->right;
	if (old_parent != NULL)
	{
		old_parent->left = old_right;
		if (old_right != NULL)
			old_right->parent = old_parent;
	}
	if (temp2->right != NULL)
		temp2->right->parent = temp2;
	free(temp);
}
/**
 * bst_remove - removes a node
 * Description: frees a node from a binary search tree
 * @root: root node of the tree
 * @value: the value of the node
 * Return: root of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);
	temp = root;
	while (temp)
	{
		if (value == temp->n)
		{
			if (temp->left == NULL && temp->right == NULL)
			{
				if (temp == root)
					root = NULL;
				else
				{
					if (temp->parent->left == temp)
						temp->parent->left = NULL;
					else
						temp->parent->right = NULL;
				}
				free(temp);
				return (root);
			}
			else if (temp->left == NULL)
				swap(temp, temp->right, &root);
			else if (temp->right == NULL)
				swap(temp, temp->left, &root);
			else
				swap_with_successor(temp, &root);
			return (root);
		}
		else if (value > temp->n)
			temp = temp->right;
		else if (value < temp->n)
			temp = temp->left;
	}
	return (root);
}
