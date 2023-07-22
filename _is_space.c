#include "main.h"

/**
 * is_space - a function that indicates if a string is only spaces.
 *
 * @s: the string.
 *
 * Return: true of false.
 */

int is_space(char *s)
{
	while (*s != '\0')
	{
		if (!isspace((unsigned char)*s))
			return (0);
		s++;
	}
	return (1);
}
