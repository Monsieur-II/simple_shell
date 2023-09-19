#include "main.h"

/**
 * _strlen - prints length of string pointed by *s
 * @s: pointer to string
 *
 * Return: 0;
 */
int _strlen(const char *s)
{
	int a = 0;

	for (; *s++;)
		a++;
	return (a);
}

/**
 * _strncmp - compares pointers to two strings
 * @s1: pointer to string 1
 * @s2: pointer to string 2
 * @n: maximum no. of characters to compare
 *
 * Return: if str1 < str2, the neg. difference of
 * the first unmatched characters
 *	if s1 == s2, 0
 *	if s1 > s2, the pos. difference of
 *	the first unmatched characters
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

		if (s1[i] == '\0')
			break;
	}

	return (0);
}

/**
 * _atoi - converts string to an integer
 * @s: the string
 *
 * Return: converted integer or zero if none
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	while (*s)
	{
		if (*s == '-')
			sign = sign * -1;

		else if (*s >= '0' && *s <= '9')
			break;
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		num = (num * 10) + (*s - '0');
		s++;
	}

	return (num * sign);
}

/**
 * _memset - function fill the first @n bytes of the memory area pointed
 * to by @s with the constant byte @b
 *
 * @n: bytes of the memory area pointed to by @s
 *
 * @s: with the constant byte @b
 *
 * @b: memory area pointer
 *
 * Return: a pointer to the memory area @s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}

	return (s);
}
