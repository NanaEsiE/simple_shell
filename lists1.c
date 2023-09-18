#include "shell.h"

/**
<<<<<<< HEAD
 * list_length - determins the length of a list to be linked.
 * @p: pointer to the first node.
 * Return: the size of a list
=======
 * list_len - determines linked list length
 * @h: first node ptr input
 *
 * Return: 0 (size of list)
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
 */
size_t list_length(const list_t *p)
{
	size_t l = 0;

	while (p)
	{
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
 * list_to_strings - returns an array of the strings of the list->str.
 * @hrd: pointer to the first node.
 * Return: an array of strings.
=======
 * list_to_strings - ret array of strs of the list->str
 * @head: first node ptr input
 *
 * Return: 0 (array of strs)
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
 */
char **list_to_strings(list_t *hrd)
{
<<<<<<< HEAD
	list_t *node = hrd;
	size_t l = list_len(hrd), k;
	char **strs;
	char *str;

	if (!hrd || !l)
=======
	list_t *node = head;
	size_t l = list_len(head), g;
	char **strs;
	char *str;

	if (!head || !l)
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
		return (NULL);
	strs = malloc(sizeof(char *) * (l + 1));
	if (!strs)
		return (NULL);
	for (l = 0; node; node = node->next, l++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
<<<<<<< HEAD
			for (k = 0; k < l; k++)
				free(strs[k]);
=======
			for (g = 0; g < l; g++)
				free(strs[g]);
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[l] = str;
	}
	strs[l] = NULL;
	return (strs);
}

/**
<<<<<<< HEAD
 * prints_list - this prints all the elements of list_t linked list.
 * @p: pointer to the very first node.
 *
 * Return: the size of a list.
=======
 * print_list - prints list_t linked list elements
 * @h: first node ptr input
 *
 * Return: 0 (size of list)
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
 */
size_t prints_list(const list_t *p)
{
	size_t l = 0;

	while (p)
	{
		_puts(convert_number(p->num, 10, 0));
		_putchar(':');
		_putchar(' ');
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
 * node_starts_wif - this returns the node whose string starts with a prefix.
 * @nodee: a pointer to the head of list.
 * @prefx: a string matching prefix.
 * @xtr: the next xter after prefix to match.
=======
 * node_starts_with - ret string starts with node prefix
 * @node: ptr list head input
 * @prefix: str input
 * @b: nxt xter after prefix to input
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
 *
 * Return: 0 (match node or null)
 */
<<<<<<< HEAD
list_t *node_starts_wif(list_t *nodee, char *prefx, char xtr)
{
	char *pp = NULL;
=======
list_t *node_starts_with(list_t *node, char *prefix, char b)
{
	char *q = NULL;
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99

	while (nodee)
	{
<<<<<<< HEAD
		pp = starts_with(nodee->str, prefx);
		if (pp && ((xtr == -1) || (*pp == xtr)))
			return (nodee);
		nodee = nodee->next;
=======
		q = starts_with(node->str, prefix);
		if (q && ((b == -1) || (*q == b)))
			return (node);
		node = node->next;
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
	}
	return (NULL);
}

/**
<<<<<<< HEAD
 * gets_node_index - this gets index of node used.
 * @hrd: pointer to head of list.
 * @nodee: pointer to the node used.
 *
 * Return: the index of node or -1
=======
 * get_node_index - get node index
 * @head: ptr list head input
 * @node: ptr node
 *
 * Return: 0 (index of node or -1)
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
 */
ssize_t gets_node_index(list_t *hrd, list_t *nodee)
{
	size_t l = 0;

	while (hrd)
	{
<<<<<<< HEAD
		if (hrd == nodee)
			return (l);
		hrd = hrd->next;
=======
		if (head == node)
			return (l);
		head = head->next;
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
		l++;
	}
	return (-1);
}
