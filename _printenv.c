#include "main.h"
/**
* _printenv - print enviroment
* @envp: global enviroment
*
* Return: void
*/
void _printenv(char **envp)
{
	size_t count = 0;

	while (envp[count])
	{
		write(STDOUT_FILENO, envp[count], _strlen(envp[count]));
		write(STDOUT_FILENO, "\n", 1);
		count++;
	}
}
