#include "main.h"

/**
 * handle_builtin - handle builtin commands.
 *
 * @args: a pointer to the commands.
 *
 * Return: return true in success. false otherwise.
 */
bool handle_builtin(char **args)
{
	if (_strcmp(args[0], "exit") == 0)
		exit_func(args);

	else if (_strcmp(args[0], "env"))
		env_func(args);
	else
		return (false);
	return (true);
}

/**
 * env_func - Implement the env built-in, that prints the current environment.
 *
 * @args: a pointer to the commands.
 *
 * Return: returns 0 (success). -1 otherwise.
 */
int env_func(char **args)
{
	int i;
	(void)args;

	if (!environ)
		return (-1);
	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 2);
	}


	return (0);

}

/**
 * exit_func - Implement the exit built-in, that exits the shell.
 *
 * @args: a pointer to the commands.
 *
 * Return: no return.
 */
void exit_func(char **args)
{
	int status;

	if (args[1])
		status = _atoi(args[1]);
	status = EXIT_SUCCESS;
	exit(status);
}
