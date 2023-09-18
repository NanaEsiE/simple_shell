#include "shell.h"

/**
 * iss_cmd - determines executable command files.
 * @infor: the infor structure.
 * @p: the path to the file.
 *
 * Return: 1 if true, 0 otherwise
 */
int iss_cmd(info_t *infor, char *p)
{
	struct stat stt;

	(void)infor;
	if (!p || stat(p, &stt))
		return (0);

	if (stt.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_xtrs - this duplicates the characters.
 * @pst: the PATH string used.
 * @strt: starting the index.
 * @stopp: stopping the index.
 * Return: a pointer to new buffer.
 */
char *dup_xtrs(char *pst, int strt, int stopp)
{
	static char buff[1024];
	int l = 0, k = 0;

	for (k = 0, l = strt; l < stopp; l++)
		if (pst[l] != ':')
			buff[k++] = pst[l];
	buff[k] = 0;
	return (buff);
}

/**
 * finds_path - this finds the cmd in the PATH string used.
 * @infor: the info structure.
 * @pst: the PATH string used.
 * @tcmd: the cmd find.
 *
 * Return: full path of the cmd if found or NULL.
 */
char *finds_path(info_t *infor, char *pst, char *tcmd)
{
	int l = 0, curr_pos = 0;
	char *path;

	if (!pst)
		return (NULL);
	if ((_strlen(tcmd) > 2) && starts_with(tcmd, "./"))
	{
		if (is_cmd(infor, tcmd))
			return (tcmd);
	}
	while (1)
	{
		if (!pst[l] || pst[l] == ':')
		{
			path = dup_chars(pst, curr_pos, l);
			if (!*path)
				_strcat(path, tcmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, tcmd);
			}
			if (is_cmd(infor, path))
				return (path);
			if (!pst[l])
				break;
			curr_pos = l;
		}
		l++;
	}
	return (NULL);
}
