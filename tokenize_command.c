#include "main.h"

/**
 * tokenize_command - searches for PATH in ENVIRON global variable.
 *
 * @command: pointer to global var environ.
 * @delimiter: in this is :
 * @count: integer count for how many connands
 * Return: string containing the PATH`.
 */
char **tokenize_command(char *command, const char *delimiter, int *count)
{
	char *line, *token, **argv;
	int i;

	line = malloc(sizeof(char *) * (strlen(command) + 1));
	if (line == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	strcpy(line, command);
	*count = 0;
	token = strtok(line, delimiter);
	while (token)
	{
		(*count)++;
		token = strtok(NULL, delimiter);
	}
	argv = malloc(sizeof(char *) * (*count + 1));
	if (argv == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	token = strtok(command, delimiter);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (argv[i] == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		strcpy(argv[i], token);
		token = strtok(NULL, delimiter);
	}
	argv[i] = NULL;
	free(line);
	return (argv);
}
