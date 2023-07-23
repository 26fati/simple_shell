#include "main.h"

/**
 * _trim - a function removes white space
 * @s: the string to get the length.
 * Return: void.
 */

void _trim(char *s)
{
	char *d = s;

	do {
		while (*d == ' ')
		{
			++d;
		}
	} while ((*s++ = *d++));
}
