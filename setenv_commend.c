#include "main.h"

/**
 * setenv_command - a function that sets variable.
 *
 * @name: the first sring representing the name.
 * @val: the second string represention the value.
 * @overwrite: an integer
 * Return: integer.
 */


int setenv_command(char *name, char *val, int overwrite)
{
	char *var = name, *value = val, *env_var = NULL, *joined;
	size_t i = 0, j = 0, k;

	if (name == NULL || *name == '\0')
	{
		write(2, "./hsh: Invalid argument\n", 24);
		return (-1);
	}

	while (environ[i] != NULL)
	{
		env_var = environ[i];
		j = 0;
		while (env_var[j] == var[j] && env_var[j] != '=' && env_var[j] && var[j])
			j++;
		if (var[j] == '\0' && overwrite != 0)
		{
			k = 0;
			while (value[k])
			{
				environ[i][j + 1 + k] = value[k];
				k++;
			}
			environ[i][j + 1 + k] = '\0';
			break;
		}
		i++;
	}

	if (!environ[i])
	{
		joined = join('=', name, value);
		environ[i] = joined;
		environ[i + 1] = '\0';
	}

	return (0);
}

/**
 * unsetenv_command - a function that unsets variable.
 *
 * @name: the first sring representing the name in eniron to unset.
 * Return: integer.
 */

int unsetenv_command(char *name)
{
	char *var = name;
	size_t i = 0, j = 0;
	char *env_var = NULL;

	if (name == NULL || *name == '\0')
	{
		write(2, "./hsh: Invalid argument\n", 24);
		return (-1);
	}

	while (environ[i] != NULL)
	{
		env_var = environ[i];
		j = 0;
		while (env_var[j] == var[j] && env_var[j] != '=' && env_var[j] && var[j])
			j++;
		if (var[j] == '\0')
		{
			environ[i] = environ[i + 1];
			while (environ[++i])
			{
				environ[i] = environ[i + 1];
			}
			break;
		}
		i++;
	}
	return (0);
}
