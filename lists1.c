#include "shell.h"

/**
 * list_length - determins the length of a list to be linked.
 * @p: pointer to the first node.
 * Return: the size of a list
 */
size_t list_length(const list_t *p)
{
	size_t l = 0;

	while (p)
	{
		p = p->next;
		l++;
	}
	return (l);
}

/**
 * list_to_strings - returns an array of the strings of the list->str.
 * @hrd: pointer to the first node.
 * Return: an array of strings.
 */
char **list_to_strings(list_t *hrd)
{
	list_t *node = hrd;
	size_t l = list_len(hrd), k;
	char **strs;
	char *str;

	if (!hrd || !l)
		return (NULL);
	strs = malloc(sizeof(char *) * (l + 1));
	if (!strs)
		return (NULL);
	for (l = 0; node; node = node->next, l++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (k = 0; k < l; k++)
				free(strs[k]);
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
 * prints_list - this prints all the elements of list_t linked list.
 * @p: pointer to the very first node.
 *
 * Return: the size of a list.
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
		p = p->next;
		l++;
	}
	return (l);
}

/**
 * node_starts_wif - this returns the node whose string starts with a prefix.
 * @nodee: a pointer to the head of list.
 * @prefx: a string matching prefix.
 * @xtr: the next xter after prefix to match.
 *
 * Return: match node or null
 */
list_t *node_starts_wif(list_t *nodee, char *prefx, char xtr)
{
	char *pp = NULL;

	while (nodee)
	{
		pp = starts_with(nodee->str, prefx);
		if (pp && ((xtr == -1) || (*pp == xtr)))
			return (nodee);
		nodee = nodee->next;
	}
	return (NULL);
}

/**
 * gets_node_index - this gets index of node used.
 * @hrd: pointer to head of list.
 * @nodee: pointer to the node used.
 *
 * Return: the index of node or -1
 */
ssize_t gets_node_index(list_t *hrd, list_t *nodee)
{
	size_t l = 0;

	while (hrd)
	{
		if (hrd == nodee)
			return (l);
		hrd = hrd->next;
		l++;
	}
	return (-1);
}
