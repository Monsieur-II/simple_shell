#include "main.h"

/**
 * addCount - adds number to string
 * @str: the string
 * @num: the number
 *
 * Return: nothing
 */

void addCount(char *str, int num)
{
	char numStr[20];
	int temp = num;
	int digCount = 0;
	int i;

	if (temp == 0)
		digCount++;

	while (temp != 0)
	{
		digCount++;
		temp /= 10;
	}

	if (digCount < 20)
	{
		for (i = 1; i <= digCount; i++)
		{
			numStr[digCount - i] = '0'  + (num % 10);
			num /= 10;
		}
		numStr[digCount] = '\0';
		_strcat(str, numStr);
	}
}

/**
 * p_error - prints error message to stderr
 * @argv: program name
 * @args: command name
 * @count: command count
 *
 * Return: nothing
 */
void p_error(char *argv, char *args, int count)
{
	char arr[MAX_COMMAND_LEN];

	_strcpy(arr, argv);
	_strcat(arr, ": ");
	addCount(arr, count);
	_strcat(arr, ": ");
	_strcat(arr, args);
	_strcat(arr, ": ");
	_strcat(arr, "not found\n");

	write(STDERR_FILENO, arr, _strlen(arr));
}

/**
 * handle_ctrl_c - handles ctrl + c signal
 * @signal: the signal number
 *
 * Return: nothing
 */

void handle_ctrl_c(int signal)
{
	if (signal == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
