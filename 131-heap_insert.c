#include "binary_trees.h"

/**
 * pushq - pushes a node
 * Description: pushes a node into a queue
 * @head: head of queue
 * @node: binary_tree node to add
 */
void pushq(binary_tree_t *node, queue_t *head)
{
	queue_t *temp = head, *newt;

	newt = malloc(sizeof(queue_t));
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
void pop(queue_t **head)
{
	queue_t *temp;

	if ((*head) == NULL)
		return;
	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * swap_with_p - swaps node with parent
 * @node: node to swap
 * @parent: parent to swap
 */
void swap_with_p(heap_t *node, heap_t *parent)
{
	heap_t *grandparent, *node_left, *node_right;
	heap_t *parent_left, *parent_right;

	grandparent = parent->parent;
	node_left = node->left;
	node_right = node->right;
	parent_left = parent->left;
	parent_right = parent->right;
	if (grandparent)
	{
		if (grandparent->left == parent)
			grandparent->left = node;
		else
			grandparent->right = node;
	}
	node->parent = grandparent;
	parent->parent = node;
	if (parent_right != node)
	{
		node->right = parent_right;
		if (parent_right)
			parent_right->parent = node;
		node->left = parent;
	}
	else
	{
		node->left = parent_left;
		if (parent_left)
			parent_left->parent = node;
		node->right = parent;
	}
	parent->left = node_left;
	parent->right = node_right;
	if (node_right)
		node_right->parent = parent;
	if (node_left)
		node_left->parent = parent;
}
/**
 * siftup - push node up
 * @node: node to push
 * @root: root of the tree
 */
void siftup(heap_t *node, heap_t **root)
{
	if (node->parent == NULL)
	{
		*root = node;
		return;
	}
	if (node->n <= node->parent->n)
		return;
	swap_with_p(node, node->parent);
	siftup(node, root);
}
/**
 * heap_insert - inserts node into a heap
 * @value: value of the node
 * @root: pointer to the root
 * Return: inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	queue_t *head, *temp;
	heap_t *new;

	if (root == NULL)
		return (NULL);
	new = binary_tree_node(NULL, value);
	if (new == NULL)
		return (NULL);
	if (*root == NULL)
		return (*root = new);
	head = malloc(sizeof(queue_t));
	head->node = *root;
	head->next = NULL;
	temp = head;
	while (temp != NULL)
	{
		if (temp->node->left == NULL)
		{
			temp->node->left = new;
			new->parent = temp->node;
			siftup(new, root);
			break;
		}
		pushq(temp->node->left, head);
		if (temp->node->right == NULL)
		{
			temp->node->right = new;
			new->parent = temp->node;
			siftup(new, root);
			break;
		}
		pushq(temp->node->right, head);
		temp = temp->next;
	}
	while (head)
		pop(&head);
	return (new);
}
