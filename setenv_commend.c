#include "main.h"
/*
void setenv_command(char **environ, char **argv) {
    char * var = argv[1];
    char * value = argv[2];

    if (var && value) {
        
        // setenv(argv[1], argv[2], 1);
        if (search_env_var(environ, argv[1])) {
            // printf("var already exist\n");
            
        }

        else {
            const char * joined = join('=',argv[1], argv[2]);
            printf("%s\n", joined);
            int res = add_environment_variable(&environ, joined);
        }
    }
    
    else{
        printf("ooops\n");
    }
}

bool search_env_var(char **env, char *var_to_search)
{
  char **env_var;
  env_var = env;

  if (env == NULL) return false;

  for (; *env_var; env_var++)
  {
    if (index_of_substring(*env_var, var_to_search) == 0 ){
        return true;
    }
  }
  return false;
}


int index_of_substring(char *str, char *substr) {
    int str_len = _strlen(str);
    int substr_len = _strlen(substr);

    for (int i = 0; i <= str_len - substr_len; i++) {
        bool found = true;
        for (int j = 0; j < substr_len; j++) {
            if (str[i + j] != substr[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i; 
        }
    }

    return -1; 
}

void _setenv(char **arv)
{
    int i, j, k;

    // Check if both the variable name and value are provided
    if (!arv[1] || !arv[2])
    {
        perror(_getenv("_")); // Print an error message with the program name
        return;
    }

    // Loop through the existing environment variables
    for (i = 0; environ[i]; i++)
    {
        j = 0;

        // Check if the variable name in arv matches the one in the environment
        if (arv[1][j] == environ[i][j])
        {
            // Compare each character of the variable name until the end of the name
            while (arv[1][j])
            {
                if (arv[1][j] != environ[i][j])
                    break;

                j++;
            }

            // If the variable name in arv matches the one in the environment
            if (arv[1][j] == '\0')
            {
                k = 0;
                // Copy the new value from arv to the existing environment variable
                while (arv[2][k])
                {
                    environ[i][j + 1 + k] = arv[2][k];
                    k++;
                }
                environ[i][j + 1 + k] = '\0'; // Null-terminate the new value
                return;
            }
        }
    }

    // If the loop reaches here, it means the variable does not exist in the environment

    // Allocate memory and create a new environment variable string with the format "name=value"
    environ[i] = concat_all(arv[1], "=", arv[2]);
    environ[i + 1] = '\0'; // Set the next element to NULL to mark the end of the environment array
}
*/
int setenv_command(char *name, char *val, int overwrite)
{
	char *var = name;
	char *value = val;
	size_t i = 0, j = 0, k;
	char *env_var = NULL;
	
	if (name == NULL || *name == '\0' || _strchr(name, '=') != NULL)
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
	
	if(!environ[i])
	{
	char * joined = join('=',name, value);
	environ[i] = joined;
	environ[i + 1] = '\0';
	}
	return (0);

}
