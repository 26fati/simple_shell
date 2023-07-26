#include "main.h"


/**
 * execute_command_directly - execute the
 * comamnd direcltly when the full path is given
 * @argv: Pointer to the array of string  containing the arguments.
 *
 * Return: void.
 */

void execute_command_directly(char **argv)
{
	int status, status_code;
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		exit(EXIT_FAILURE);
	}

	else if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./hsh");
		}
	}
	else
	{
		int res = waitpid(pid, &status, 0);

		if (res == -1)
		{
			perror("waitpid");
		}

			/*this for task 4*/
			if (WIFEXITED(status))
			{
				status_code = WEXITSTATUS(status);
				if (status_code != 0)
				{
					_exit(2);
				}
			};
	}
}

/**
 * try_execute_with_paths - execute the comamnd after
 *  joining it with every possible path in PATH
 * @argv: Pointer to the array of string  containing the arguments.
 * @paths_arr: Pointer to the array of string  all
 *  possible path for executing a command.
 * @tokens_path_len: the number of paht to check
 *
 * Return: void.
 */

void try_execute_with_paths(char **argv, char **paths_arr,
int tokens_path_len)
{
	int i;
	char *full_path = NULL;

	for (i = 0; i < tokens_path_len; i++)
	{
		full_path = join('/', paths_arr[i], argv[0]);
		if (file_exist(full_path))
		{
			if (fork() == 0)
			{
				if (execve(full_path, argv, environ) == -1)
					perror("./hsh");
			}
			else
			{
				wait(NULL);
			}
			free(full_path);
			return; /* Exit the function if the command was found and executed. */
		}
		free(full_path);
	}

	/* If the command is not found in any path, display an error message. */
	write(2, "./hsh: 1: ", 10);
	write(2, argv[0], _strlen(argv[0]));
	write(2, ": not found\n", 12);
	exit(127);
}
