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
 * binary_tree_is_complete - check if tree is complete
 * Discription: check if levels are complete and last level filled from left
 * @tree: pointer to the root
 * Return: 1 if complete 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	ancestors_t *head, *temp;
	int res = 1;

	if (tree == NULL)
		return (0);
	head = malloc(sizeof(ancestors_t));
	head->node = tree;
	head->next = NULL;
	pushq(head->node->left, head);
	pushq(head->node->right, head);
	temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		if (temp != NULL)
		{
			if (temp->node != NULL)
			{
				pushq(temp->node->left, temp);
				pushq(temp->node->right, temp);
			}
			else
				while (temp != NULL)
				{
					temp = temp->next;
					if (temp != NULL)
						res = (temp->node != NULL) ? 0 : res;
					pop(&head);
				}
		}
		pop(&head);
	}
	return (res);
}
