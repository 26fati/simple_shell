#include "main.h"

char * _get_paths(char **env) {
    char **env_var;
    char *paths = NULL;
    env_var = env;
    size_t prefix_len = 5;
    /*
        prefix length is to avoid return PATH=/HOME/BIN/ ONLY  /HOME/BIN
    */

    for (; *env_var; env_var++) {

        if ((*env_var)[0] == 'P' && (*env_var)[1] == 'A' && (*env_var)[2] == 'T' && (*env_var)[3] == 'H') {

            // printf("%s\n", *env_var);

            // printf("length of path is %d\n", _strlen(*env_var));
            int path_len = _strlen(*env_var) + 1;
            paths = (char *)malloc(sizeof(char) * path_len - prefix_len);

            _strcpy(paths, *(env_var) + prefix_len);

        }
    }

    return (paths);
}

char **  _get_path_tokens(char *paths) {
    char *token, *p1, *p2;
    char **arr_tokens;
    int i;
    size_t  num_tokens;

    p1 = (char *)malloc(sizeof(char) *_strlen(paths) + 1);
    _strcpy(p1, paths);

    p2 = (char *)malloc(sizeof(char) *_strlen(paths) + 1);
    _strcpy(p2, paths);

    token = strtok(p1, ":");
    num_tokens = 0;

    while (token)
    {
      num_tokens++;
      token = strtok(NULL, ":");
    }
    

    arr_tokens = (char **)malloc(sizeof(char *) * num_tokens);

    token = strtok(p2, ":");
    for (i = 0; token != NULL; i++)
    {
      arr_tokens[i] = malloc(sizeof(char) * (_strlen(token) + 1));
      _strcpy(arr_tokens[i], token);
      token = strtok(NULL, ":");
    }

    free(p1);
    free(p2);

    return (arr_tokens);
}


/**
 * file_exist - checks if the file exists.
 *
 * @filePath: the file path.
 *
 * Return: returns 1 in success. otherwise 0. // command false , path true
 */
int file_exist(const char *file_path)
{
	struct stat buffer;

	if (stat(file_path, &buffer) == 0)
		return (1);
	return (0);

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
char *join(const char sep, const char *path1, const char *path2) {
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
