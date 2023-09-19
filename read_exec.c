#include "main.h"

/**
 * read_input - reads user input and stores it in a buffer
 * @line_read: address of pointer to buffer
 * @n: address of size of buffer variable
 *
 * Return: nothing
 */

void read_input(char **line_read, size_t *n)
{
	if (_getline(line_read, n, STDIN_FILENO) == -1)
	{
		_free(line_read);
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
}

/**
 * find_command - looks through PATH to find command
 * @args: array of tokenized user input
 *
 * Return: pointer to string of full path,
 * NULL on failure
 */

char *find_command(char **args)
{
	char *path_var = _getenv("PATH");
	char *path = _strdup(path_var);
	char command_path[MAX_COMMAND_LEN];
	char *dir = strtok(path, ":");

	while (dir)
	{
		if (_strchr(args[0], '/') != NULL)
			_strcpy(command_path, args[0]);

		else
		{
			_strcpy(command_path, dir);
			_strcat(command_path, "/");
			_strcat(command_path, args[0]);
		}

		if (access(command_path, X_OK) == 0)
		{
			free(path);
			return (_strdup(command_path));
		}

		dir = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}

/**
 * execute_command - executes command using execve
 * @command_path: string containing full command path
 * @args: array of command line arguments
 *
 * Return: status of execution
 */

int execute_command(char *command_path, char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	else if (pid == 0)
	{
		if (execve(command_path, args, environ) == -1)
			exit(EXIT_FAILURE);
	}

	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (0);
}

/**
 * tokenize - separates input into arguments
 * @str: input
 * @args: array of arguments
 * @max_args: maximum no. of arguments
 * @delimiters: delimiters
 *
 * Return: nothing
 */

void tokenize(char *str, char **args, int max_args, char *delimiters)
{
	char *token = strtok(str, delimiters);
	int i = 0;

	while (token != NULL && i < max_args)
	{
		args[i++] = token;
		token = strtok(NULL, delimiters);
	}

	args[i] = NULL;
}
