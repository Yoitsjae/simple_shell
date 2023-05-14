#include "shell.h"

/**
 * signalhandler - handle signal
 * @sigid: sognal
 * Return: void
 */

void signalhandler(int sigid)
{
	if (sigid == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
}
