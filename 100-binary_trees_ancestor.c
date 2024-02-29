#include "binary_trees.h"

/**
 * free_list - frees list
 * Description: starts from head and deletes entire linked list
 * @head: head of list
 * Return: nothing
 */
void free_list(ancestors_t *head)
{
	ancestors_t *temp1 = head;
	ancestors_t *temp2;

	if (head == NULL)
		return;
	while (temp1)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		free(temp2);
	}

}

/**
 * ancestors_number - helper function
 * Description: returns number of ancestors for a node
 *              and inserts them in a linked list
 * @parent: the node to check for ancestors
 * @ancestor: the head of the linked list
 * Return: number of ancestors
 */
size_t ancestors_number(binary_tree_t *parent, ancestors_t *ancestor)
{
	size_t ancestors = 0;

	while (parent != NULL)
	{
		ancestors_t *new = malloc(sizeof(ancestors_t));

		ancestors += 1;
		new->node = parent;
		new->next = NULL;
		ancestor->next = new;
		ancestor = new;
		parent = parent->parent;
	}
	return (ancestors);
}
/**
 * binary_trees_ancestor - returns common ancestor
 * Description: returns lowest common anscetor
 * @first: first node
 * @second: second node
 * Return: ancestor node or NULL
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *first_parent, *second_parent, *r_n;
	size_t first_ancestors = 0, second_ancestors = 0;
	ancestors_t *f_head, *s_head, *temp, *s_temp1, *f_temp1;

	if (first == NULL || second == NULL)
		return (NULL);
	first_parent = first->parent;
	second_parent = second->parent;
	f_head = malloc(sizeof(ancestors_t));
	f_head->node = first;
	f_head->next = NULL;
	s_head = malloc(sizeof(ancestors_t));
	s_head->node = second;
	s_head->next = NULL;
	temp = f_head;
	first_ancestors = ancestors_number(first_parent, temp);
	temp = s_head;
	second_ancestors = ancestors_number(second_parent, temp);
	f_temp1 = f_head;
	s_temp1 = s_head;
	while (first_ancestors > second_ancestors)
	{
		first_ancestors -= 1;
		f_head = f_head->next;
	}
	while (first_ancestors < second_ancestors)
	{
		second_ancestors -= 1;
		s_head = s_head->next;
	}
	while (s_head != NULL && s_head->node != f_head->node)
	{
		s_head = s_head->next;
		f_head = f_head->next;
	}
	r_n = (s_head != NULL) ? (binary_tree_t *)s_head->node : NULL;
	free_list(f_temp1);
	free_list(s_temp1);
	return (r_n);

}
