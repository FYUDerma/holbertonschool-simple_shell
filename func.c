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
