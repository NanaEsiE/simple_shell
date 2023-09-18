#include "shell.h"

/**
 * is_cmd - check if a file is an executable cmd
 * return 1 if true, 0 otherwise
 * @info: info struct type
 * @path: file path
 *
 * Return: 0 (command path)
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - characters duplication
 * @pathstr: str path
 * @start: index input starting
 * @stop: index stopping
 *
 * Return: 0 (ptr to new buff)
 */
char *dup_chars(char *pathstr, int start, int stop)
{
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
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int l = 0, curr_ptr = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[l] || pathstr[l] == ':')
		{
			path = dup_chars(pathstr, curr_ptr, l);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[l])
				break;
			curr_ptr = l;
		}
		l++;
	}
	return (NULL);
}
