#include "main.h"

/**
 * main - entry point
 * Return: integer.
 */

int main(void)
{
	char *prompt = "($) ", *command = NULL, **paths_arr, **argv, *paths;
	size_t command_size = 0, command_len;
	char *delimiter = " \t\n";
	int count = 0, tokens_path_len = 0;
	bool is_built_in = false;

	while (1)
	{
		paths = _get_paths(environ);
		paths_arr = _get_path_tokens(paths);
		tokens_path_len = path_arr_length(paths_arr);
		write(0, prompt, 5);
		command_len = getline(&command, &command_size, stdin);
		printf("command is %s\n", command);
		if ((int)command_len == -1)
		{
			/*Handle newline character before exiting*/
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		if (is_space(command))
			continue;
		argv = tokenize_command(command, delimiter, &count);
		is_built_in = false;
		handle_builtin_commands(argv, environ, &is_built_in);
		if (is_built_in)
		{
			cleanup_memory(argv, paths_arr, paths);
			continue;
		}
		if (file_exist(argv[0]))
			execute_command_directly(argv);
		else
			try_execute_with_paths(argv, paths_arr, tokens_path_len);
		cleanup_memory(argv, paths_arr, paths);
		free(command);
		command = NULL;
	}
	return (0);
}

/**
 * cleanup_memory - entry point
 * @argv: Pointer to the array of string  containing the arguments.
 * @paths_arr: Pointer to the array of string  all
 * @paths: possible path for executing a command.
 * Return: void.
 */


void cleanup_memory(char **argv, char **paths_arr, char *paths)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);

	if (paths_arr != NULL)
	{
		for (i = 0; paths_arr[i] != NULL; i++)
			free(paths_arr[i]);
		free(paths_arr);
		free(paths);
	}
}
