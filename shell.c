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
	int i = 0, count = 0, tokens_path_len = 0;
	bool is_built_in = false;

	paths = _get_paths(environ);
	paths_arr = _get_path_tokens(paths);
	tokens_path_len = path_arr_length(paths_arr);

	while (1)
	{
		write(0, prompt, 5);
		command_len = getline(&command, &command_size, stdin);
		if ((int)command_len == -1)
			exit(EXIT_SUCCESS);

		if (is_space(command))
			continue;

		argv = tokenize_command(command, delimiter, &count);
		is_built_in = false;
		handle_builtin_commands(argv, environ, &is_built_in);

		if (is_built_in)
			continue;

		if (file_exist(argv[0]))
			execute_command_directly(argv);
		else
			try_execute_with_paths(argv, paths_arr, tokens_path_len);

		for (i = 0; i < count; i++)
			free(argv[i]);
	}

	return (0);
}
