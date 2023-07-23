#include "main.h"

/**
 * _strjoin - a function that concatenates two string and returns a new string.
 *
 * @str1: the first sring.
 * @str2: the second string.
 *
 * Return: new string.
 */

char *_strjoin(char *str1, char *str2)
{
	int str1_len, str2_len, i;
	char *n_str;

	str1_len = strlen(str1);
	str2_len = strlen(str2);
	n_str = malloc(sizeof(char) * (str1_len + str2_len + 1));

	for (i = 0; i < str1_len; i++)
		n_str[i] = str1[i];

	for (i = 0; i < str2_len; i++)
		n_str[str1_len + i] = str2[i];

	n_str[str1_len + str2_len] = '\0';

	return (n_str);
}
