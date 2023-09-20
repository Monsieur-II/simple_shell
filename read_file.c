#include "main.h"

/**
 * read_file - entry point
 * @argv: arg vector
 * @line_read: buffer
 * @args: arguments
 * @command_path: cmd
 * @n: size of buffer
 *
 * Return: nothing
 */

void read_file(char **argv, char *line_read, char **args,
			   char *command_path, size_t n)
{
	int counter = 0, status = 0;
	char str[250];
	FILE *file = NULL;

	file = fopen(argv[1], "r");
	if (!file)
	{
		file_error(argv, counter);
		exit(127);
	}
	while (getline(&line_read, &n, file) != -1)
	{
		handle_comment(line_read);
		tokenize(line_read, args, MAX_ARGS, "\n\t ");
		if (args[0] == NULL)
		{
			_free(&line_read);
			continue;
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
		_free(&line_read);
	}
	_free(&line_read);
	fclose(file);
	exit(status);
}
