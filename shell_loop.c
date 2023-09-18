#include "shell.h"

/**
 * hsl - main shell loop used.
 * @infor: the parameter & return infor structure.
 * @avc: the argument vector from main() used.
 * Return: 0 for success, 1 for error, or the error code.
 */
int hsl(info_t *infor, char **avc)
{
	ssize_t rp = 0;
	int builtin_ret = 0;

	while (rp != -1 && builtin_ret != -2)
	{
		clear_info(infor);
		if (interactive(infor))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		rp = get_input(infor);
		if (rp != -1)
		{
			set_info(infor, avc);
			builtin_ret = find_builtin(infor);
			if (builtin_ret == -1)
				find_cmd(infor);
		}
		else if (interactive(infor))
			_putchar('\n');
		free_info(infor, 0);
	}
	write_history(infor);
	free_info(infor, 1);
	if (!interactive(infor) && infor->status)
		exit(infor->status);
	if (builtin_ret == -2)
	{
		if (infor->err_num == -1)
			exit(infor->status);
		exit(infor->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - this finds builtin command.
 * @infor: the parameter & return infor structure.
 * Return: -1 if the builtin is not found,
 *	0 if the builtin executed is successfully,
 *	1 if the builtin is found but not successful,
 *	2 if the builtin signals exit().
 */
int find_builtin(info_t *infor)
{
	int a, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (a = 0; builtintbl[a].type; a++)
		if (_strcmp(infor->argv[0], builtintbl[a].type) == 0)
		{
			infor->line_count++;
			built_in_ret = builtintbl[a].func(infor);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - this finds a command in the PATH.
 * @infor: the parameter & return infor structure.
 * Return: void or nil.
 */
void find_cmd(info_t *infor)
{
	char *path = NULL;
	int a, p;

	infor->path = infor->argv[0];
	if (infor->linecount_flag == 1)
	{
		infor->line_count++;
		infor->linecount_flag = 0;
	}
	for (a = 0, p = 0; infor->arg[a]; a++)
		if (!is_delim(infor->arg[a], " \t\n"))
			p++;
	if (!p)
		return;

	path = find_path(infor, _getenv(infor, "PATH="), infor->argv[0]);
	if (path)
	{
		infor->path = path;
		fork_cmd(infor);
	}
	else
	{
		if ((interactive(infor) || _getenv(infor, "PATH=")
					|| infor->argv[0][0] == '/') && is_cmd(infor, infor->argv[0]))
			fork_cmd(infor);
		else if (*(infor->arg) != '\n')
		{
			infor->status = 127;
			print_error(infor, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks an execu thread to run the cmd.
 * @infor: the parameter & return infor structure.
 * Return: void when needed.
 */
void fork_cmd(info_t *infor)
{
	pid_t child_pld;

	child_pld = fork();
	if (child_pld == -1)
	{
		/* TODO: PUTS ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pld == 0)
	{
		if (execve(infor->path, infor->argv, get_environ(infor)) == -1)
		{
			free_info(infor, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUTS ERROR FUNCTION */
	}
	else
	{
		wait(&(infor->status));
		if (WIFEXITED(infor->status))
		{
			infor->status = WEXITSTATUS(infor->status);
			if (infor->status == 126)
				print_error(infor, "Permission denied\n");
		}
	}
}
