#include "main.h"

#include <stdio.h>
#include <unistd.h>

/**
 * cd_command - Searches for PATH in the ENVIRON global variable.
 * @path: where to go whith cd
 * @environ: Pointer to the global variable environ.
 *
 * Return: String containing the PATH.
 */

int cd_command(char *path, char **environ)
{
	char buff[1024], *oldpwd, *home;
	int status;

	getcwd(buff, sizeof(buff));
	oldpwd = _get_old_working_dir(environ);
	if (oldpwd == NULL)
		return (1);
	if (path == NULL)
	{
		home = _get_home(environ);
		return (change_to_home_directory(buff, home, oldpwd));
	}
	if (!_strcmp(path, "-"))
	{
		if (chdir(oldpwd) == 0)
		{
			setenv_command("OLDPWD", buff, 2);
			free(oldpwd);
			return (0);
		}
		else
			free(oldpwd);
		return (1);
	}
	status = chdir(path);
	if (status == 0)
	{
		setenv_command("OLDPWD", buff, 2);
		free(oldpwd);
		return (0);
	}
	if (errno == EACCES || errno == ENOENT)
		print_cd_error(path, oldpwd);
	return (1);
}

/**
 * _get_home - Searches for PATH in the ENVIRON global variable.
 * @environ: Pointer to the global variable environ.
 *
 * Return: String containing the PATH.
 */
char *_get_home(char **environ)
{
	char **env_var;
	char *paths = NULL;
	size_t prefix_len = 5;
	int path_len;

	env_var = environ;
	if (environ == NULL)
		return (NULL);

	/*
	 * prefix length is to avoid return PATH=/HOME/BIN/ ONLY  /HOME/BIN
	 */
	for (; *env_var; env_var++)
	{

		if ((*env_var)[0] == 'H' && (*env_var)[1] == 'O' &&
			(*env_var)[2] == 'M' && (*env_var)[3] == 'E')
		{
			path_len = _strlen(*env_var) + 1;
			paths = (char *)malloc(sizeof(char) * (path_len - prefix_len));
			_strcpy(paths, *(env_var) + prefix_len);
		}
	}
	return (paths);
}

/**
 * _get_old_working_dir - Searches for PATH in the ENVIRON global variable.
 * @environ: Pointer to the global variable environ.
 *
 * Return: String containing the PATH.
 */
char *_get_old_working_dir(char **environ)
{
	char **env_var;
	char *paths = NULL;
	size_t prefix_len = 7;
	int path_len;

	env_var = environ;

	if (environ == NULL)
		return (NULL);

	/*
	 * prefix length is to avoid return PATH=/HOME/BIN/ ONLY  /HOME/BIN
	 */
	for (; *env_var; env_var++)
	{

		if ((*env_var)[0] == 'O' && (*env_var)[1] == 'L' && (*env_var)[2] == 'D' &&
			(*env_var)[3] == 'P' && (*env_var)[4] == 'W' && (*env_var)[5] == 'D')
		{
			path_len = _strlen(*env_var) + 1;
			paths = (char *)malloc(sizeof(char) * (path_len - prefix_len));
			_strcpy(paths, *(env_var) + prefix_len);
		}
	}
	return (paths);
}


/**
 * change_to_home_directory - changes to home directory.
 * @buff: buffer.
 * @home: home path.
 * @oldpwd: old working directory path.
 *
 * Return: int.
 */

int change_to_home_directory(char *buff, char *home, char *oldpwd)
{
	if (chdir(home) == 0)
	{
		setenv_command("OLDPWD", buff, 2);
		free_cd(home, oldpwd);
		return (0);
	}
	else
	{
		free_cd(home, oldpwd);
		print_cd_error(home, oldpwd);
		return (1);
	}
}

