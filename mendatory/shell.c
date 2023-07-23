#include "main.h"

/**
 * main - entry point
 * Return: integer.
 */

int main(void)
{/* printf("before anything\n"); */
	char *prompt = "($) ";
	char *command, **paths_arr;
	size_t command_size = 0;
	ssize_t command_len;
	char **argv;
	char *delimiter = " \t\n";
	int i, count = 0, tokens_path_len;
	char *paths = _get_paths(environ);

	paths_arr = _get_path_tokens(paths);
	tokens_path_len = path_arr_length(paths_arr);
	/* printf("token path len %d\n", tokens_path_len); */
	while (1)
	{
		write(0, prompt, 5);
		command_len = getline(&command, &command_size, stdin);

		if (command_len == -1)
			exit(EXIT_SUCCESS);
		if (is_space(command))
			continue;
		argv = tokenize_command(command, delimiter, &count);
		if (!_strcmp(argv[0], "exit"))
		{
			exit(EXIT_SUCCESS);
		}
		if (!_strcmp(argv[0], "env"))
		{
			_printenv(environ);
			continue;
		}
		if (file_exist(argv[0]))
			execute_command_directly(argv);
		else
			try_execute_with_paths(argv, paths_arr, tokens_path_len);
		for (i = 0; i < count; i++)
			free(argv[i]);
	}
	return (0);
}
