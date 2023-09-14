#include "shell.h"

/**
 * interactive - if shell is interactive mode return true
 * otherwise return fals
 * @info: address of struct type
 *
 * Return: 0 (interactive)
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - prints if the xter is delimeter
 * @x: xter input to check
 * @delim: delimeter str
 *
 * Return: 0 (delimeter)
 */
int is_delim(char x, char *delim)
{
	while (*delim)
		if (*delim++ == x)
			return (1);
	return (0);
}

/**
 * _isalpha - prints an alphabetic xtr
 * @x: xter to input
 *
 * Return: 0 (alphabets)
 */

int _isalpha(int x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - ASCII to integer converter
 * @c: the converted str
 *
 * Return: 0 (atoi)
 */

int _atoi(char *c)
{
	int x, sign = 1, flag = 0, prints;
	unsigned int out_put = 0;

	for (x = 0; c[x] != '\0' && flag != 2; x++)
	{
		if (c[x] == '-')
			sign *= -1;

		if (c[x] >= '0' && c[x] <= '9')
		{
			flag = 1;
			out_put *= 10;
			out_put += (c[x] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		prints = -out_put;
	else
		prints = out_put;

	return (prints);
}
