#include "shell.h"

/**
<<<<<<< HEAD
 * iss_cmd - determines executable command files.
 * @infor: the infor structure.
 * @p: the path to the file.
=======
 * is_cmd - check if a file is an executable cmd
 * return 1 if true, 0 otherwise
 * @info: info struct type
 * @path: file path
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
 *
 * Return: 0 (command path)
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
<<<<<<< HEAD
 * dup_xtrs - this duplicates the characters.
 * @pst: the PATH string used.
 * @strt: starting the index.
 * @stopp: stopping the index.
 * Return: a pointer to new buffer.
=======
 * dup_chars - characters duplication
 * @pathstr: str path
 * @start: index input starting
 * @stop: index stopping
 *
 * Return: 0 (ptr to new buff)
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
 */
char *dup_xtrs(char *pst, int strt, int stopp)
{
<<<<<<< HEAD
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
=======
	static char buf[1024];
	int l = 0, q = 0;

	for (q = 0, l = start; l < stop; l++)
		if (pathstr[l] != ':')
			buf[q++] = pathstr[l];
	buf[q] = 0;
	return (buf);
}

/**
 * find_path - finds str path command
 * @info: info struct type
 * @pathstr: str path
 * @cmd: command to find
 *
 * Return: 0 (full path of cmd if found or NULL)
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
 */
char *finds_path(info_t *infor, char *pst, char *tcmd)
{
<<<<<<< HEAD
	int l = 0, curr_pos = 0;
=======
	int l = 0, curr_ptr = 0;
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
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
<<<<<<< HEAD
		if (!pst[l] || pst[l] == ':')
		{
			path = dup_chars(pst, curr_pos, l);
=======
		if (!pathstr[l] || pathstr[l] == ':')
		{
			path = dup_chars(pathstr, curr_ptr, l);
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
			if (!*path)
				_strcat(path, tcmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, tcmd);
			}
			if (is_cmd(infor, path))
				return (path);
<<<<<<< HEAD
			if (!pst[l])
				break;
			curr_pos = l;
=======
			if (!pathstr[l])
				break;
			curr_ptr = l;
>>>>>>> 8978fc5d3d2fe904a6e2bfe9b53103896c1fec99
		}
		l++;
	}
	return (NULL);
}
