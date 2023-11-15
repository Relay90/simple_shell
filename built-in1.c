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
 * env_shell - This function handles the built-in 'env' command in the shell.
 * @args: Array of strings representing the arguments passed
 * @line: User input buffer.
 * @env: Environment (list of environment variables).
 */
void env_shell(char **args, char *line, char **env)
{
	int i;

	(void)args;
	(void)line;


	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
