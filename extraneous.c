#include "shell.h"

/**
 * _strcmp - Compares two strings, s1 and s2
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: 0 if s1 and s2 are equal.
 *          Positive value if s1 is greater than s2.
 *          Negative value if s1 is less than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * prompt - prints $ for prompt
 * Return: void
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(1, "$ ", 2);
	}
}

/**
 * _strstr - Locates a substring needle in a string haystack
 * @haystack: The string to search in
 * @needle: The substring to find.
 *
 * Return: A pointer to the start of the substring in haystack if found.
 * NULL if needle is not found in haystack.
 */
char *_strstr(const char *haystack, const char *needle)
{
	while (*haystack)
	{
		const char *h = haystack;
		const char *n = needle;

		while (*h && *n && (*h == *n))
		{
			h++;
			n++;
		}

		if (!*n)
		{
			return ((char *)haystack);
		}

		haystack++;
	}

	return (NULL);
}

/**
 * _strlen - Calculates the length of a string.
 *
 * @s: Pointer to the input string.
 *
 * Return: The length of the input string.
 */
int _strlen(char *s)
{
	char *p = s;

	while (*p != '\0')
	{
		p++;
	}
	return (p - s);
}
