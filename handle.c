#include "shell.h"

#define MAX_ARGS 100
#define MAX_PATH_LENGTH 256

/**
 * execute_command - Executes a command by tokenizing it into arguments
 * and using fork and execvp
 * @command: string representing the command to be executed.
 */
void execute_command(char *command)
{
	pid_t pid;
	char *args[MAX_ARGS];
	int i = 0;
	char *token = strtok(command, " ");

	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	pid = fork();

	if (pid < 0)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		perror("Exec error");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
/**
 * handle_command - Searches for and executes a command
 * @input: string representing the command to be executed
 * @env: An array of strings representing the environment variables.
 */
void handle_command(char *input, char **env)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);

	char *token = strtok(path_copy, ":");
	int command_found = 0;
	char command_path[MAX_PATH_LENGTH];

	(void)env;

	while (token != NULL)
	{
	snprintf(command_path, sizeof(command_path), "%s/%s", token, input);
	if (access(command_path, X_OK) == 0)
	{
		execute_command(command_path);
		command_found = 1;
		break;
	}
	token = strtok(NULL, ":");
	}

	if (!command_found)
	{
		printf("Command not found\n");
	}

	free(path_copy);
}
/**
 * shell - implementation that continuously prompts
 * @ac: The number of arguments passed to the shell
 * @av: An array of strings representing the shell's command-line arguments.
 * @env: array of strings representing the environment variables.
 */
void shell(int ac, char **av, char **env)
{
	char input[MAX_PATH_LENGTH];

	(void)ac;
	(void)av;
	(void)env;

	while (1)
	{
		printf(":) ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		input[strcspn(input, "\n")] = '\0';

		handle_command(input, env);
	}
}
