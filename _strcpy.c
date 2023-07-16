#include "main.h"

/**
 * _strcpy - a function that copies the string pointed to by src.
 *
 * @dest: destination of the string.
 * @src: source of the string.
 *
 * Return: no return.
 */
char *_strcpy(char *dest, char *src)
{
	char *pointer = dest;

	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
		*dest = 0;
	}
	return (pointer);
}
