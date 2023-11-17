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
 * shell - Handles the shell functionality
 * @ac: Arg count
 * @av: Arr of args
 * @env: Environment
 */
void shell(int ac, char **av, char **env)
{
	char input[1024];
	char *command;
	char **args = malloc(sizeof(char *) * 64);
	char *line = malloc(sizeof(char) * 1024);

	(void)ac;
	(void)av;
	(void)env;

	if (args == NULL || line == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		printf("$ ");
		fgets(input, sizeof(input), stdin);

		if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n'))
		{
			input[strlen(input) - 1] = '\0';
		}

		command = strtok(input, " ");

		if (command != NULL)
		{
			if (strcmp(command, "exit") == 0)
				exit(0);
		}
				else
				{
				printf("Command not recognized: %s\n", command);
				}
	}
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
