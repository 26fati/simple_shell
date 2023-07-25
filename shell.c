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
		paths = _get_paths(environ);
		paths_arr = _get_path_tokens(paths);
		tokens_path_len = path_arr_length(paths_arr);

	while (1)
	{
		write(0, prompt, 5);
		command_len = getline(&command, &command_size, stdin);
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
		/* argv = split_line(command);
		// free(command); */
		is_built_in = false;
		handle_builtin_commands(argv, environ, &is_built_in);

		if (is_built_in)
		{
			cleanup_memory(argv, paths_arr, paths);
			continue;
		}

		if (file_exist(argv[0])){
			/* printf("file exist\n"); */
			execute_command_directly(argv);
		}
		else{
			/* printf("file not exist\n"); */
			try_execute_with_paths(argv, paths_arr, tokens_path_len);
		}
	

		/* cleanup_memory(argv, paths_arr, paths); */
	}

	return (0);
}


void cleanup_memory(char **argv, char **paths_arr, char *paths)
{
    int i;

    /* Free argv and its elements */
    for (i = 0; argv[i] != NULL; i++)
        free(argv[i]);
    free(argv);

    /*  Free paths_arr and its elements */
	if (paths_arr != NULL) {
		for (i = 0; paths_arr[i] != NULL; i++)
			free(paths_arr[i]);
		free(paths_arr);
   		free(paths);
	}


}

