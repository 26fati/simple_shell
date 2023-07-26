#include "main.h"


/**
 * handle_builtin_commands - to habdle builtin commands.
 *
 * @argv: list of arguments
 * @environ: global variable env.
 * @executed: if any of the builtin commands getexecuted it turns into true.
 * @paths_arr: array of paths.
 * @paths: string of paths.
 * @tokens_path_len: number of paths.
 * Return: void.
 */


void handle_builtin_commands(char **argv, char **environ,
bool *executed, char **paths_arr, char *paths, int tokens_path_len)
{
	if (!_strcmp(argv[0], "exit"))
	{
		*executed = true;
		cleanup_memory_no_argv(paths_arr, paths, tokens_path_len);
		exit_command(argv);
	}
	else if (!_strcmp(argv[0], "env"))
	{
		*executed = true;
		_printenv(environ);
	}
	else if (!_strcmp(argv[0], "setenv"))
	{
		*executed = true;
		setenv_command(argv[1], argv[2], 2);
	}
	else if (!_strcmp(argv[0], "unsetenv"))
	{
		*executed = true;
		unsetenv_command(argv[1]);
	}
	else if (!_strcmp(argv[0], "cd"))
	{
		*executed = true;
		cd_command(argv[1], environ);
	}
}
