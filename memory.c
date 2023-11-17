#include "shell.h"

/**
 * _calloc - Mimics the behavior of calloc in C, allocating memory
 * @nmemb: Number of elements in the array
 * @size: Size of each element
 *
 * Return: 0 or NULL if allocation fails or if nmemb or size is zero
 */
void *_calloc(size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
	void *ptr = malloc(total_size);

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	if (ptr == NULL)
	{
		return (NULL);
	}

	memset(ptr, 0, total_size);

	return (ptr);
}

