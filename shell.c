#include "main.h"

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 *
 * Return: (0)
 */

int main(int argc __attribute__((unused)), char **argv)
{
	char *line_read = NULL, *args[MAX_ARGS + 1], *command_path = NULL;
	size_t n = 0;
	int counter = 0;

	signal(SIGINT, handle_ctrl_c);
	while (1)
	{
		non_int(argv, line_read, args, command_path, n);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		read_input(&line_read, &n);
		counter++;
		tokenize(line_read, args, MAX_ARGS, "\n ");

		if (args[0] == NULL)
		{
			_free(&line_read);
			continue;
		}

		if (built_in(&line_read, args) == 0)
			continue;

		command_path = find_command(args);

		if (command_path == NULL)
			p_error(argv[0], args[0], counter);

		else
		{
			execute_command(command_path, args);
			free(command_path);
		}
		_free(&line_read);
	}
	return (0);
}
