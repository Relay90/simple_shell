#include "shell.h"

/**
 * exit_shell - This function handles the built-in 'exit' command in the shell.
 * @args: Array of strings representing the arguments passed
 * @line: User input buffer.
 * @env: Environment (list of environment variables).
 */
void exit_shell(char **args, char *line, char **env)
{
	int i;

	(void)env; /* Avoid unused variable warning */

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
	free(line);

	exit(0);
}
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
