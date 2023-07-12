#include "main.h"
/**
 * *_strdup - a function that returns a pointer to a newly allocated
 * space in memory, which contains a copy of the string given as a parameter.
 *
 * @str: a pointer to a string.
 *
 * Return:  returns a pointer to the duplicated string,
 * it returns NULL if insufficient memory was available.
 */
char *_strdup(char *str)
{
	int i = 0, size = 0;
	char *arr;

	if (str == NULL)
		return (NULL);
	for (; str[size] != '\0'; size++)
	;
	arr = malloc(size * sizeof(*str) + 1);
	if (arr == 0)
	{
		return (NULL);
	}
	else
	{
	while (i < size)
	{
		arr[i] = str[i];
		i++;
	}
	}
	return (arr);
}
