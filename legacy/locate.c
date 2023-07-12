#include "main.h"

/**
 * _getenv - get the environment variables.
 *
 * @name: name of variable.
 *
 * Return: return a pointer to the variable.
 */

extern char **environ;
char *_getenv(const char *name)
{
	size_t i = 0, j;
	char *env_var = NULL;

	while (environ[i] != NULL)
	{
		env_var = environ[i];
		j = 0;
		while (env_var[j] == name[j] && env_var[j] != '=' && env_var[j] && name[j])
			j++;

		if (name[j] == '\0')
			return (_strdup(env_var));
		i++;

	}
	return (NULL);

}

/**
 * locate - locate the file of the command.
 *
 * @name: name of the command.
 *
 * Return: returns the path of the file.
 */
char *locate(const char *name)
{
	char *dir_path;
	char *env_var;
	char *file_path = NULL;

	env_var = _getenv("PATH");
	if (file_exist(name))
		return ((char *)name);

	strtok(env_var, "=");
	dir_path = strtok(NULL, ":");
	while (dir_path)
	{
		file_path = join('/', dir_path, name);
		if (file_exist(file_path))
		{
			free(env_var);
			return (file_path);
		}
		free(file_path);
		file_path = NULL;

		dir_path = strtok(NULL, ":");
	}
	free(env_var);
	return (file_path);

}

/**
 * join - join two paths with seperator,
 *
 * @sep: seperator,
 * @path1: the first path.
 * @path2: the second path.
 *
 * Return: returns the joined path..
 */
char *join(const char sep, const char *path1, const char *path2)
{
	char *dir_path;
	int i, k, len = 0;

	if (!path1 || !path2 || sep == '\0')
		return (NULL);
	for (i = 0; path1[i] != '\0'; i++)
		;
	len += i;
	for (i = 0; path2[i] != '\0'; i++)
		;
	len += i;
	len++;
	dir_path = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (path1[i])
	{
		dir_path[i] = path1[i];
		i++;
	}
	dir_path[i] = sep;
	i++;
	k = 0;
	while (path2[k])
	{
		dir_path[i] = path2[k];
		i++;
		k++;
	}
	dir_path[i] = '\0';
	return (dir_path);


}

/**
 * file_exist - checks if the file exists.
 *
 * @filePath: the file path.
 *
 * Return: returns 1 in success. otherwise 0.
 */
int file_exist(const char *filePath)
{
	struct stat buffer;

	if (stat(filePath, &buffer) == 0)
		return (1);
	return (0);

}
