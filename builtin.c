#include "main.h"

/**
 * exit_shell - exits program
 * @line_read: pointer to input buffer
 * @args: array of args
 * @argv: command line args
 * @status: address of status
 * @counter: command counter
 *
 * Return: nothing
 */

void exit_shell(char **line_read, char **args, char **argv,
				int *status, int counter)
{
	unsigned int a;
	unsigned char ch;

	if (args[1] == NULL)
	{
		_free(line_read);
		exit(EXIT_SUCCESS);
	}

	else if (check_digit(args[1]) == 0)
	{
		a = _atoi(args[1]);
		ch = (unsigned char)a;

		_free(line_read);
		exit((int)ch);
	}

	else
	{
		exit_error(argv[0], args, counter);
		*status = 2;
		_free(line_read);
	}
}

/**
 * _env - prints environment
 * @line_read: pointer to input buffer
 * @args: array of args
 * @argv: command line args
 * @status: address of status
 * @counter: command counter
 *
 * Return: nothing
 */

void _env(char **line_read, __attribute__((unused)) char **args,
		  char **argv, int *status, int counter)
{
	int i, j;

	(void)argv;
	(void)counter;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
			write(STDOUT_FILENO, &environ[i][j], 1);

		write(STDOUT_FILENO, "\n", 1);
	}

	_free(line_read);
	*status = 0;
}

/**
 * built_in - checks for builtin
 * @line_read: pointer to input buffer
 * @args: argument array
 * @argv: command line args
 * @status: address of status
 * @counter: command counter
 *
 * Return: (0) if builtin found, -1 otherwise
 */

int built_in(char **line_read, char **args, char **argv,
			 int *status, int counter)
{
	int i;
	blt arr[] = {
		{"exit", exit_shell},
		{"env", _env},
		{NULL, NULL}};

	for (i = 0; arr[i].s != NULL; i++)
	{
		if (_strcmp(args[0], arr[i].s) == 0)
		{
			arr[i].f(line_read, args, argv, status, counter);
			return (0);
		}
	}

	return (-1);
}
