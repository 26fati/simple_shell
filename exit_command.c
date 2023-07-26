#include "main.h"


/**
 * exit_command - exit
 * @argv: Pointer to the array of string  containing the arguments.
 * Return: void.
 */
void exit_command(char **argv)
{
	int exit_status = 0;

	if (!argv[1])
	{
		free(argv[0]);
		free(argv);
		exit(EXIT_SUCCESS);
	}

	exit_status = _atoi(argv[1]); /* exit LAKJF134 */

	if (has_non_numerical_chars(argv[1]) || exit_status < 0)
	{
		write(2, "./hsh: 1: ", 10);
		write(2, argv[0], _strlen(argv[0]));
		write(2, ": Illegal number: ", 18);
		write(2, argv[1], _strlen(argv[1]));
		write(2, "\n", 1);
		free(argv[0]);
		free(argv[1]);
		free(argv);
		exit(2);
	}

	if (exit_status >= 0)
	{
		free(argv[0]);
		free(argv[1]);
		free(argv);
		exit(exit_status);
	}
}

/**
 * has_non_numerical_chars - check is a string has no numrical chars
 * @str: strint to check
 * Return: true or flase.
 */

bool has_non_numerical_chars(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			return (true);
		}
		str++;
	}
	return (false);
}
