#include "shell.h"

/**
 * search_cwd - look for current working dir
 * @filename: Pointer to a character array representing the filename to search
 * @er: Pointer to a character array representing an error message.
 * Return: current working dir
 */
char *search_cwd(char *filename, char *er)
{
	DIR *dir;
	struct dirent *sd;
	char *ret;
	int i, len = strlen(filename);

	ret = (char *)malloc((len + 3) * sizeof(char));
	if (ret == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	dir = opendir(".");
	if (dir == NULL)
	{
		perror("opendir");
		exit(EXIT_FAILURE);
	}
	while ((sd = readdir(dir)) != NULL)
	{
		for (i = 0; sd->d_name[i] == filename[i]; i++)
		{
			if (filename[i] == '\0')
			{
				sprintf(ret, "./%s", filename);

				if (access(ret, X_OK) == 0)
				{
					closedir(dir);
				}
				else
				{
					write(STDERR_FILENO, er, strlen(er));
					free(ret);
					closedir(dir);
					return (NULL);
				}
			}
		}
	}
	return (er);
}
