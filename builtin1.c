#include "shell.h"

/**
 * _myhistory - list history, one command by line
 * preceded with line numb, begins 0.
 * @info: Struct contain potential arg used to maintain prototype
 *
 *  Return: 0 (builtin history)
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets str alias
 * @info: parameter struct
 * @str: str input
 *
 * Return: 0 (builtin alias)
 */
int unset_alias(info_t *info, char *str)
{
	char *q, x;
	int rtn;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	x = *q;
	*q = 0;
	rtn = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*q = x;
	return (rtn);
}

/**
 * set_alias - sets str alias
 * @info: parameter struct
 * @str: str input
 *
 * Return: 0 (builtin alias set)
 */
int set_alias(info_t *info, char *str)
{
	char *q;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints str alias
 * @node: the alias node
 *
 * Return: 0 (builtin alias prints)
 */
int print_alias(list_t *node)
{
	char *q = NULL, *z = NULL;

	if (node)
	{
		q = _strchr(node->str, '=');
		for (z = node->str; z <= q; z++)
		_putchar(*z);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - man alias
 * @info: Struct contain potential arg used to maintain valid prototype.
 *
 * Return: 0 (main builtin alias)
 */
int _myalias(info_t *info)
{
	int l = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (l = 1; info->argv[l]; l++)
	{
		q = _strchr(info->argv[l], '=');
		if (q)
			set_alias(info, info->argv[l]);
		else
			print_alias(node_starts_with(info->alias, info->argv[l], '='));
	}

	return (0);
}
