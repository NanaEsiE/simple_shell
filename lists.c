#include "shell.h"

/**
 * add_node - adds node to strt of list.
 * @hrd: addres of pointer for top node.
 * @strr: str field node.
 * @numb: node index history
 *
 * Return: size of list
 */
list_t *add_node(list_t **hrd, const char *strr, int numb)
{
	list_t *new_head;

	if (!hrd)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = numb;
	if (strr)
	{
		new_head->str = _strdup(strr);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *hrd;
	*hrd = new_head;
	return (new_head);
}

/**
 * add_node_ends - adds a node to the end of a list.
 * @hrd: addres of pointer to the head node used.
 * @strr: strr field of node.
 * @numb: node index to be used by history.
 * Return: the size of the list.
 */
list_t *add_node_ends(list_t **hrd, const char *strr, int numb)
{
	list_t *new_node, *node;

	if (!hrd)
		return (NULL);

	node = *hrd;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = numb;
	if (strr)
	{
		new_node->str = _strdup(strr);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*hrd = new_node;
	return (new_node);
}

/**
 * print_list_strr - this prints only the star element of a list_t linked list.
 * @p: pointer to the first node.
 * Return: size of the list.
 */
size_t print_list_strr(const list_t *p)
{
	size_t l = 0;

	while (p)
	{
		_puts(p->str ? p->str : "(nil)");
		_puts("\n");
	p = p->next;
		l++;
	}
	return (l);
}

/**
 * delete_node_at_indx - deletes node at the given index.
 * @hrd: addres of the pointer to first node.
 * @indx: index of node to be deleted.
 *
 * Return: To 1 when success, 0 when failure.
 */
int delete_node_at_indx(list_t **hrd, unsigned int indx)
{
	list_t *node, *prev_node;
	unsigned int l = 0;

	if (!hrd || !*hrd)
		return (0);

	if (!indx)
	{
		node = *hrd;
		*hrd = (*hrd)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *hrd;
	while (node)
	{
		if (l == indx)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		l++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * frees_list - frees nodes of list.
 * @hrd_ptrr: address of pointer to head node.
 * Return: void return.
 */
void frees_list(list_t **hrd_ptrr)
{
	list_t *node, *next_node, *hrd;

	if (!hrd_ptrr || !*hrd_ptrr)
		return;
	hrd = *hrd_ptrr;
	node = hrd;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*hrd_ptrr = NULL;
}
