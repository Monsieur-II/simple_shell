#include "main.h"

/**
 * exit_shell - exits program
 * @line_read: pointer to input buffer
 *
 * Return: nothing
 */

void exit_shell(char **line_read)
{
	_free(line_read);
	exit(EXIT_SUCCESS);
}

/**
 * _env - prints environment
 * @line_read: pointer to input buffer
 *
 * Return: nothing
 */

void _env(char **line_read)
{
	int i, j;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
			write(STDOUT_FILENO, &environ[i][j], 1);

		write(STDOUT_FILENO, "\n", 1);
	}

	_free(line_read);
}

/**
 * built_in - checks for builtin
 * @line_read: pointer to input buffer
 * @args: argument array
 *
 * Return: (0) if builtin found, -1 otherwise
 */

int built_in(char **line_read, char **args)
{
	int i;
	blt arr[] = {
		{"exit", exit_shell},
		{"env", _env},
		{NULL, NULL}
	};

	for (i = 0; arr[i].s != NULL; i++)
	{
		if (_strcmp(args[0], arr[i].s) == 0)
		{
			arr[i].f(line_read);
			return (0);
		}
	}

	return (-1);
}
