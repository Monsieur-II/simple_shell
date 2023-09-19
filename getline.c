#include "main.h"

/**
 * _getline - reads a line from a stream and stores it
 * in a dynamically allocated buffer.
 * @lineptr: address of the buffer
 * @n: pointer to the size of the buffer
 * @fd: the file descriptor to read from
 *
 * Return: the number of bytes read on success, -1 on error
 */

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	static size_t buff_size = INITIAL_BUFFER_SIZE;
	size_t n_read = 0;
	char *buf = *lineptr;

	if (buf == NULL || *n < buff_size)
	{
		buff_size = INITIAL_BUFFER_SIZE;

		buf = _realloc(buf, *n, buff_size);
		if (buf == NULL)
			return (-1);
		*n = buff_size; /* update both */
		*lineptr = buf;
	}

	else
		buff_size = *n;

	while ((n_read = read(fd, buf, (buff_size - 1))) > 0) /*no error*/
	{
		if (buf[n_read - 1] == '\n')
			break; /* break upon newline */
		if ((buff_size - 1) > n_read)
		{
			break; /* if buff_size - 1 > n_read it means the whole file has been read */
		}
		else
		{
			buff_size = *n * 2;
			buf = _realloc(buf, *n, buff_size);
			if (buf == NULL)
				return (-1);
			*lineptr = buf;
			*n = buff_size;
		}
	}
	if (n_read == 0 || (int)n_read == -1)
		return (-1);
	buf[n_read] = '\0'; /* terminate buffer */
	return (n_read);
}
