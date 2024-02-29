#include "binary_trees.h"

/**
 * pushq - pushes a node
 * Description: pushes a node into a queue
 * @head: head of queue
 * @node: binary_tree node to add
 */
void pushq(binary_tree_t *node, ancestors_t *head)
{
	ancestors_t *temp = head, *newt;

	newt = malloc(sizeof(ancestors_t));
	newt->node = node;
	newt->next = NULL;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newt;
}
/**
 * pop - deletes node
 * Description: deletes and frees the head of a queue
 * @head: head
 */
void pop(ancestors_t **head)
{
	ancestors_t *temp;

	if ((*head) == NULL)
		return;
	temp = (*head)->next;
	free(*head);
	*head = temp;
}
/**
 * binary_tree_levelorder - traverse tree by level
 * Discription: traverse tree from first level to last level
 * @tree: pointer to the root
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ancestors_t *head, *temp;

	if (tree == NULL || func == NULL)
		return;
	head = malloc(sizeof(ancestors_t));
	head->node = tree;
	head->next = NULL;
	if (head->node->left != NULL)
		pushq(head->node->left, head);
	if (head->node->right != NULL)
		pushq(head->node->right, head);
	temp = head;
	while (temp != NULL)
	{
		func(temp->node->n);
		temp = temp->next;
		if (temp != NULL)
		{
			if (temp->node->left != NULL)
				pushq(temp->node->left, temp);
			if (temp->node->right != NULL)
				pushq(temp->node->right, temp);
		}
		pop(&head);
	}
}
