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
	int counter = 0, status = 0;
	char str[250];

	if (!(isatty(STDIN_FILENO)))
	{

		while (getline(&line_read, &n, stdin) != -1)
		{
			handle_comment(line_read);
			tokenize(line_read, args, MAX_ARGS, "\n\t ");

			if (args[0] == NULL)
			{
				_free(&line_read);
				exit(EXIT_SUCCESS);
			}
			counter++;

			handle_dollar(args, status, str);

			if (built_in(&line_read, args, argv, &status, counter) == 0)
				continue;

			command_path = find_command(args);

			if (command_path == NULL)
			{
				p_error(argv[0], args[0], counter);
				status = 127;
			}

			else
			{
				status = execute_command(command_path, args);
				free(command_path);
			}
		}
		_free(&line_read);
		exit(status);
	}
}
