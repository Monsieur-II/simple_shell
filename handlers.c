#include "main.h"

/**
 * handle_comment - ignores comments
 * @s: the string to handle
 *
 * Return: nothing
 */
void handle_comment(char *s)
{
	int i = 0, j;

	while (s[i])
	{
		if (s[i] == '#')
		{
			for (j = i; s[j]; j++)
				s[j] = '\0';

			return;
		}
		i++;
	}
}

/**
 * check_digit - checks if string is a digit
 * @s: the string to check
 *
 * Return: 0 if digit, 1 otherwise
 */
int check_digit(char *s)
{
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (1);

		s++;
	}

	return (0);
}

/**
 * handle_dollar - handles shell expansion
 * @args: array of command line args
 * @status: status of previous command
 * @str: auxilliary string
 *
 * Return: nothing
 */
void handle_dollar(char **args, int status, char *str)
{
	int i, j;
	char *temp = NULL, *path = NULL, *ptr = NULL;

	_memset(str, '\0', 250);

	for (i = 0; args[i]; i++)
	{
		ptr = args[i];
		if ((args[i][0] == '$') && args[i][1])
		{
			if (_strcmp(args[i], "$?") == 0)
			{
				addCount(str, status);
				args[i] = str;
				return;
			}

			else if (_strcmp(args[i], "$$") == 0)
			{
				j = (int)getpid();
				addCount(str, j);
				args[i] = str;
				return;
			}

			else
			{
				ptr++;
				temp = _getenv(ptr);
				if (temp)
				{
					path = _strdup(temp);
					_strcat(str, path);
					args[i] = str;
					free(path);
					return;
				}
			}
		}
	}
}
