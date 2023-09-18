#include "shell.h"

/**
<<<<<<< HEAD
 * add_node - adds node to strt of list.
 * @hrd: addres of pointer for top node.
 * @strr: str field node.
 * @numb: node index history
=======
 * add_node - adds a node to the start of linked list
 * @head: ptr address to head node
 * @str: str field of node
 * @num: node index
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
 *
 * Return: 0 (size of list)
 */
list_t *add_node(list_t **hrd, const char *strr, int numb)
{
	list_t *newhead;

	if (!hrd)
		return (NULL);
	newhead = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
<<<<<<< HEAD
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = numb;
	if (strr)
	{
		new_head->str = _strdup(strr);
		if (!new_head->str)
=======
	_memset((void *)newhead, 0, sizeof(list_t));
	newhead->num = num;
	if (str)
	{
		newhead->str = _strdup(str);
		if (!newhead->str)
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
		{
			free(newhead);
			return (NULL);
		}
	}
<<<<<<< HEAD
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
=======
	newhead->next = *head;
	*head = newhead;
	return (newhead);
}

/**
 * add_node_end - adds node to the list end
 * @head: ptr to head node
 * @str: str node fielded
 * @num: node index used by history
 *
 * Return: 0 (size of list)
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
 */
list_t *add_node_ends(list_t **hrd, const char *strr, int numb)
{
	list_t *newnode, *node;

	if (!hrd)
		return (NULL);

<<<<<<< HEAD
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
=======
	node = *head;
	newnode = malloc(sizeof(list_t));
	if (!newnode)
		return (NULL);
	_memset((void *)newnode, 0, sizeof(list_t));
	newnode->num = num;
	if (str)
	{
		newnode->str = _strdup(str);
		if (!newnode->str)
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
		{
			free(newnode);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = newnode;
	}
	else
<<<<<<< HEAD
		*hrd = new_node;
	return (new_node);
}

/**
 * print_list_strr - this prints only the star element of a list_t linked list.
 * @p: pointer to the first node.
 * Return: size of the list.
=======
		*head = newnode;
	return (newnode);
}

/**
 * print_list_str - prints str element of a list_t linked list only
 * @h: ptr to first node
 *
 * Return: 0 (size of list)
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
 */
size_t print_list_strr(const list_t *p)
{
	size_t l = 0;

	while (p)
	{
		_puts(p->str ? p->str : "(nil)");
		_puts("\n");
<<<<<<< HEAD
	p = p->next;
=======
		h = h->next;
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
		l++;
	}
	return (l);
}

/**
<<<<<<< HEAD
 * delete_node_at_indx - deletes node at the given index.
 * @hrd: addres of the pointer to first node.
 * @indx: index of node to be deleted.
 *
 * Return: To 1 when success, 0 when failure.
=======
 * delete_node_at_index - deletes index of a given node
 * return 1 on success, 0 on failure
 * @head: node addr of ptr
 * @index: delete index node
 *
 * Return: 0 (index node deletion)
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
 */
int delete_node_at_indx(list_t **hrd, unsigned int indx)
{
<<<<<<< HEAD
	list_t *node, *prev_node;
=======
	list_t *node, *old_node;
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
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
<<<<<<< HEAD
		if (l == indx)
=======
		if (l == index)
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
		{
			old_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		l++;
<<<<<<< HEAD
		prev_node = node;
=======
		old_node = node;
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
		node = node->next;
	}
	return (0);
}

/**
<<<<<<< HEAD
 * frees_list - frees nodes of list.
 * @hrd_ptrr: address of pointer to head node.
 * Return: void return.
=======
 * free_list - frees all linked list node
 * @head_ptr: ptr head node
 *
 * Return: 0 (void)
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
 */
void frees_list(list_t **hrd_ptrr)
{
<<<<<<< HEAD
	list_t *node, *next_node, *hrd;
=======
	list_t *node, *nextnode, *head;
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99

	if (!hrd_ptrr || !*hrd_ptrr)
		return;
	hrd = *hrd_ptrr;
	node = hrd;
	while (node)
	{
		nextnode = node->next;
		free(node->str);
		free(node);
		node = nextnode;
	}
	*hrd_ptrr = NULL;
}
