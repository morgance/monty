#include "monty.h"
/**
 * _calloc - concatenate tw strings specially
 * @nmemb: number of elements
 * @size: type of elements
 * Return: nothing
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *s = NULL;
	unsigned int j;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	s = malloc(nmemb * size);
	if (s == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < (nmemb * size); j++)
	{
		*((char *)(s) + j) = 0;
	}
	return (s);
}
/**
 * _realloc - change the size and copy the content
 * @ptr: malloc pointer to reallocate
 * @old_size: old number of bytes
 * @new_size: new number of Bytes
 * Return: nothing
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *s = NULL;
	unsigned int j;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		s = malloc(new_size);
		if (!s)
			return (NULL);
		return (s);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		s = malloc(new_size);
		if (!s)
			return (NULL);
		for (j = 0; j < old_size; j++)
			s[j] = *((char *)ptr + j);
		free(ptr);
	}
	else
	{
		s = malloc(new_size);
		if (!s)
			return (NULL);
		for (j = 0; j < new_size; j++)
			s[j] = *((char *)ptr + j);
		free(ptr);
	}
	return (s);
}
