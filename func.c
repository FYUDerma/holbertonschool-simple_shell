#include "main.h"

/**
 * _isspace - check if character is a space
 * @c: character to check
 * Return: 1 if true, 0 if false
 */

int _isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\w' || c == '\f')
	{
		return (1);
	}
	return (0);
}

/**
 * trim - removes leading and trailing whitespace from string
 * @str: string to trim
 * Return: trimmed string
 */
char *trim(char *str)
{
	char *end = str + strlen(str) - 1;

	while (_isspace(*str))
	{
		str++;
	}

	if (*str == 0)
		return (str);

	while (end > str && _isspace(*end))
	{
		end--;
	}

	end[1] = '\0';

	return (str);
}
