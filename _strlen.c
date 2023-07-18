#include "main.h"

/**
* _strlen - a function that returns the length of a string.
*
* @s: the string to get the length.
*
* Return: the length of string.
*/
int _strlen(char *s)
{
	int count = 0;
	int i = 1;
	char s1 = s[0];

	while (s1 != '\0')
	{
		count++;
		s1 = s[i++];
	}
	return (count);
}
