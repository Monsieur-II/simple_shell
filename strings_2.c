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
