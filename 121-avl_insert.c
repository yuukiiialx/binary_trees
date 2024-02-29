#include "binary_trees.h"
/**
 * check_root - checks if node should be root
 * @node: node to check
 * @root: root to assign
 */
void check_root(avl_t *node, avl_t **root)
{
	if (node->parent == NULL)
		*root = node;
}
/**
 * balance_tree - balances avl tree
 * @node: node to start balancing from
 * @root: root to assign
 */
void balance_tree(avl_t *node, avl_t **root)
{
	avl_t *balanced;
	int balance, value = node->n;

	if (node == NULL)
		return;
	node = node->parent;
	while (node)
	{
		balance = binary_tree_balance(node);
		if (balance > 1)
			if (value > node->left->n)
			{
				balanced = binary_tree_rotate_left(node->left);
				check_root(balanced, root);
				balanced = binary_tree_rotate_right(node);
				check_root(balanced, root);
			}
			else
			{
				balanced = binary_tree_rotate_right(node);
				check_root(balanced, root);
			}
		else if (balance < -1)
		{
			if (value < node->right->n)
			{
				balanced = binary_tree_rotate_right(node->right);
				check_root(balanced, root);
				balanced = binary_tree_rotate_left(node);
				check_root(balanced, root);
			}
			else
			{
				balanced = binary_tree_rotate_left(node);
				check_root(balanced, root);
			}
		}
		node = node->parent;
	}
}
/**
 * avl_insert - inserts a value in a Balanced Binary Search Tree
 * @tree: a double pointer to the root node of the avl to insert the value
 * @value: the value to store in the node to be inserted
 * Return: A pointer to the created node
 *         NULL on failure
 */
avl_t *avl_insert(bst_t **tree, int value)
{
	avl_t *tmp = NULL, *second = NULL, *new = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	tmp = *tree;
	while (tmp)
	{
		second = tmp;
		if (value < tmp->n)
			tmp = tmp->left;
		else if (value > tmp->n)
			tmp = tmp->right;
		else if (value == tmp->n)
			return (NULL);
	}

	new = binary_tree_node(NULL, value);
	if (second == NULL)
		second = new;
	else if (value < second->n)
	{
		second->left = new;
		new->parent = second;
	}
	else
	{
		second->right = new;
		new->parent = second;
	}
	balance_tree(new, tree);
	return (new);
}
