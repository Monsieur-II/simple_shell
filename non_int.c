#include "main.h"

/**
 * non_int - entry point
 * @argv: arg vector
 * @line_read: buffer
 * @args: arguments
 * @command_path: cmd
 * @n: size of buffer
 *
 * Return: nothing
 */

void non_int(char **argv, char *line_read, char **args,
		char *command_path, size_t n)
{
	int counter = 0;

	if (!(isatty(STDIN_FILENO)))
	{

		while (getline(&line_read, &n, stdin) != -1)
		{

		tokenize(line_read, args, MAX_ARGS, "\n\t ");

		if (args[0] == NULL)
		{
			_free(&line_read);
			exit(EXIT_SUCCESS);
		}
		counter++;

		if (built_in(&line_read, args) == 0)
			exit(EXIT_SUCCESS);

		command_path = find_command(args);

		if (command_path == NULL)
			p_error(argv[0], args[0], counter);

		else
		{
			execute_command(command_path, args);
			free(command_path);
		}
		}
		_free(&line_read);
		exit(EXIT_SUCCESS);
	}
}
