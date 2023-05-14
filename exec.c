#include "shell.h"

/**
 * concat - concats 2 names
 * @pname: name 1
 * @cname: name 2
 * Return: pname + cname
 */
char *concat(char *pname, char *cname)
{
	int n, m, sz;

	n = _strlen(pname);
	m = _strlen(cname);
	sz = sizeof(char) * (n + m + 2);
	pname = _realloc(pname, (n + 1), sz);
	if (!pname)
		return (NULL);
	_strcat(pname, "/");
	_strcat(pname, cname);
	return (pname);
}

/**
 * find - fimds a command in the path
 * @cmd: command
 * Return: fullpath of command
 */

char *find(char *cmd)
{
	char *path = NULL,  **paths = NULL;
	struct stat sb;
	int i = 0;

	if (!cmd)
	{
		free(cmd);
		return (NULL);
	}
	if (stat(cmd, &sb) == 0)
		return (cmd);
	if (stat(cmd, &sb) != 0 && *cmd != '/')
	{
		path = _getenv("PATH");
		paths = split_str(path, ":");

		while (paths[i])
		{
			paths[i] = concat(paths[i], cmd);
			if (stat(paths[i], &sb) == 0)
			{
				free(cmd);
				cmd = _strdup(paths[i]);
				free(path);
				free_array(paths);
				return (cmd);
			}
			i++;
		}
	}
	free(cmd);
	return (NULL);
}

/**
 * execute - executes a command
 * @cmd: command
 * @tokens: options
 * Return: 0 if success, i if failed
 */
int execute(char *cmd, char **tokens)
{
	pid_t child;
	int status;

	if (!tokens[0] || access(tokens[0], X_OK) != 0)
		perror("./hsh");
	child = fork();
	if (child < 0)
	{
		perror("failed to create process");
		return (-1);
	}
	if (child == 0)
	{
		execve(cmd, tokens, environ);
	}
	else
	{
		do {
		waitpid(child, &status, WUNTRACED);
		} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}
	return (0);
}

