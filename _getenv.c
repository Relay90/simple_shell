#include "shell.h"

/**
 * _getenv - Retrieves the value of an environment variable specified
 * @env: The name of the environment variable to retrieve
 *
 * Return: A pointer to the character after the first '/'
 * in the value of the environment variable,
 * or NULL if the environment variable is not found or no '/' is found.
 */
char *_getenv(char *env)
{
	char *value = getenv(env);
	char *slash_position = strchr(value, '/');

	if (value == NULL)
	{
		fprintf(stderr, "Environment variable %s not found\n", env);
		return (NULL);
	}

	if (slash_position == NULL)
	{
	fprintf(stderr, "No '/' found in environment variable %s\n", env);
	return (NULL);
	}

	return (slash_position + 1);
}
