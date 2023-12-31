#include "main.h"

/**
 * main - an entry point.
 *
 * @argc: the number of arguments.
 * @av: pointer.
 *
 * Return: 0 (success).
 */
int main(int argc __attribute__((unused)), char **av __attribute__((unused)))
{
	char **argv;
	char *command_path = NULL;

	while (1)
	{
		write(0, "($) ", 5);
		argv = read_line();
		command_path = locate(argv[0]);
		if (command_path)
		{
			argv[0] = command_path;
			if (fork() == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
					perror("./shell");
			}
			else
			{
				wait(NULL);
				free(argv);
				free(command_path);
			}
		}
		/** else if (handle_builtin(argv))
		{
			free(argv);
			free(command_path);
		}
		**/
		else
		{
			if(errno == ENOENT) 
			{
				write(2, "./hsh: 1: ", 10); 
				write(2, argv[0], _strlen(argv[0]));
				write(2, ": not found\n", 12);
				exit(127);
			}
		}

		//	perror("./shell");

		
	}
	return (0);
}
