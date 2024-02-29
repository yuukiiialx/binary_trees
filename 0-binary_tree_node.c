#include "binary_trees.h"
/**
 * binary_tree_node - Entry point
 * Description: creates a new node
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: nothing
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
