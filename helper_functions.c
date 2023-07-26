#include "main.h"

/**
 * free_cd - frees memory allocated for cd.
 * @home: home path.
 * @oldpwd: old working directory path.
 *
 * Return: void.
 */

void free_cd(char *home, char *oldpwd)
{
	free(home);
	free(oldpwd);
}

/**
 * print_cd_error - prints error message for cd.
 * @path: path to print.
 * @oldpwd: old working directory path.
 * Return: void.
 */

void print_cd_error(char *path, char *oldpwd)
{
	free(oldpwd);
	write(2, "./hsh: 1: ", 10);
	write(2, "cd", 2);
	write(2, ": can't cd to ", 14);
	write(2, path, _strlen(path));
	write(2, "\n", 1);
}
