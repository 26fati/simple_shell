#include "main.h"

/**
 * _strcmp - a function that compares two strings.
 *
 * @s1: the first string.
 * @s2: the second string.
 *
 * Return: return 0 if strings are equal,
 * >0 if the first non-matching character in s1,
 *  is greater (in ASCII) than that of s2,
 * <0 if the first non-matching character in s1,
 * is lower (in ASCII) than that of s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		int a = s1[i];
		int b = s2[i];

		if (a != b)
			return (a - b);
		i++;
	}
	return (0);
}
