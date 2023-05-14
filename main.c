#include "shell.h"

/**
 * main - entry point
 * Return: 0
 */

int main(void)
{
	char *lineptr = NULL, **tokens = NULL;
	int Flag = 0;
	size_t line_sz;
	ssize_t line_len = 0;

	while (line_len == 0)
	{
		signal(SIGINT, signalhandler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		line_len = getline(&lineptr, &line_sz, stdin);
		if (line_len < 0 && isatty(STDIN_FILENO))
		{
			_putchar('\n');
			break;
		}
		tokens = split_str(lineptr, " \t\n");
		Flag = builtInexec(tokens, lineptr);
		if (!Flag)
		{
			tokens[0] = find(tokens[0]);
			execute(tokens[0], tokens);
			free_array(tokens);
		}
	}
	free(lineptr);
	return (0);
}
