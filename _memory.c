#include "main.h"

#define low(a, b) (((a) < (b)) ? (a) : (b))

/**
 * _realloc - reallocates block of memory
 * @ptr: pointer to previous memory
 * @old_size: old size
 * @new_size: new size
 *
 * Return: pointer to the new memory block
 */

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *temp;
	unsigned int i;

	if (ptr == NULL)
	{
		temp = malloc(new_size);
		return (temp);
	}

	else if (new_size == old_size)
		return (ptr);

	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	else
	{
		temp = malloc(new_size);
		if (temp != NULL)
		{
			for (i = 0; i < low(old_size, new_size); i++)
				*((char *)temp + i) = *((char *)ptr + i);

			free(ptr);
			return (temp);
		}
		else
			return (NULL);
	}
}

/**
 * _free - frees pointer pointed to by lineptr
 * @lineptr: address of pointer to be freed
 *
 * Return: nothing
 */

void _free(char **lineptr)
{
	if (*lineptr != NULL)
	{
		free(*lineptr);
		*lineptr = NULL;
	}
}
