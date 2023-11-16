#include "shell.h"

/**
 * bridge - Will check to see whether we are dealing with a builtin or not
 * @check: Figures out what to execute
 * @args: Arguments passed from cmdline broken up
 *
 * Return: 1 if user entered a path/builtin, 2 if user entered a binary
 */
int bridge(char *check, char **args)
{
	int isBuiltIn = builtins_checker(args);

	if (isBuiltIn == 1)
	{
		return (1);
	}

	if (strchr(check, '/') != NULL)
	{
		return (1);
	}

	return (2);
}
