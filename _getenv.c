#include "main.h"

/**
 * _getenv - gets an environment variable
 * @name: variable to get
 *
 * Return: pointer to string of variable
 */

char *_getenv(const char *name)
{
	char **env;
	int len = _strlen(name);

	for (env = environ; *env; env++)
	{
		if (_strncmp(name, *env, len) == 0 && (*env)[len] == '=')
			return (&(*env)[len + 1]);
	}

	return (NULL);
}
