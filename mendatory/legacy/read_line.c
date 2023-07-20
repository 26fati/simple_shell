#include "main.h"

/**
 * read_line - read from the user.
 *
 * Return: return a pointer in success.
 */
char **read_line(void)
{
	char *line = NULL, *line_copied, *token;
	size_t n = 0;
	char *delimiter = " \n";
	ssize_t char_read;
	int i, count = 0;
	char **argv;


	char_read = getline(&line, &n, stdin);
	if (char_read == -1)
		exit(EXIT_SUCCESS);
	line_copied = malloc(sizeof(char *) * char_read);
	if (line_copied == NULL)
		exit(EXIT_FAILURE);
	_strcpy(line_copied, line);
	token = strtok(line, delimiter);
	while (token)
	{
		count++;
		token = strtok(NULL, delimiter);
	}
	count++;
	argv = malloc(sizeof(char *) * count);
	if (argv == NULL)
		exit(EXIT_FAILURE);
	token = strtok(line_copied, delimiter);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		_strcpy(argv[i], token);
		token = strtok(NULL, delimiter);
	}
	argv[i] = NULL;
	free(line_copied);
	free(line);

	for (i = 0; token != NULL; i++)
	{
		free(argv[i]);
	}
/*
	free(argv);
*/	
	return (argv);



}
