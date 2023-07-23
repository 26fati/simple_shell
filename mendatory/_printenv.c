#include "main.h"
/**
* _printenv - print enviroment
* @envp: 1
*
* Return: non
*/
void _printenv(char **envp)
{
	size_t run = 0;

	while (envp[run])
	{
		write(STDOUT_FILENO, envp[run], _strlen(envp[run]));
		write(STDOUT_FILENO, "\n", 1);
		run++;
	}
}
