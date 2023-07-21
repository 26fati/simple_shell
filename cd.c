#include "main.h"

#include <stdio.h>
#include <unistd.h>

int cd_command(char *path, char **environ)
{
    char buff[1024];
    char *oldpwd;
    int status;

    getcwd(buff, sizeof(buff));
    oldpwd = _get_old_working_dir(environ);
    if (oldpwd == NULL) return 1;
     
    /*
        we go to home
    */
    if (path == NULL)
    {
        char *home = _get_home(environ);
        
        if (chdir(home) == 0) {
            setenv_command("OLDPWD", buff, 2);
            return 0; // Successfully changed to the home directory
        }
        else {
            // perror("chdir");
            return 1; // Error changing to the home directory
        }
    }

    /*
        case where the argument is "cd -" - we go to oldpwd
    */
    if (!_strcmp(path, "-")) {
        if (chdir(oldpwd) == 0) {
            setenv_command("OLDPWD", buff, 2);
            return 0; // Successfully changed to the old working directory
        }
        else {
            // perror("chdir");
            return 1; // Error changing to the old working directory
        }
    }

    status = chdir(path);
    if (status == 0)
    {
        if (getcwd(buff, sizeof(buff)) != NULL)
        {
            // printf("Current working directory: %s\n", buff);
        }
        return 0; // Successfully changed to the specified directory
    }
    else
    {
        if (errno == EACCES || errno == ENOENT) {
            write(2, "./hsh: 1: ", 10); 
            write(2, "cd", 2);
            write(2, ": can't cd to ", 14);
            write(2, path, _strlen(path));
            write(2, "\n", 1);
            // exit(2);
        }
        // perror("chdir");
        return 1; // Error changing to the specified directory
    }
}


/**
 * _get_home - Searches for PATH in the ENVIRON global variable.
 * @env: Pointer to the global variable environ.
 *
 * Return: String containing the PATH.
 */
char *_get_home(char **environ)
{
    char **env_var;
    char *paths = NULL;
    size_t prefix_len = 5;
    env_var = environ;

    if (environ == NULL)
        return NULL;

    /*
     * prefix length is to avoid return PATH=/HOME/BIN/ ONLY  /HOME/BIN
     */
    for (; *env_var; env_var++)
    {

        if ((*env_var)[0] == 'H' && (*env_var)[1] == 'O' && (*env_var)[2] == 'M' && (*env_var)[3] == 'E')
        {
            int path_len = _strlen(*env_var) + 1;
            paths = (char *)malloc(sizeof(char) * (path_len - prefix_len));
            _strcpy(paths, *(env_var) + prefix_len);
        }
    }
    return (paths);
}

/**
 * _get_home - Searches for PATH in the ENVIRON global variable.
 * @env: Pointer to the global variable environ.
 *
 * Return: String containing the PATH.
 */
char *_get_old_working_dir(char **environ)
{
    char **env_var;
    char *paths = NULL;
    size_t prefix_len = 7;
    env_var = environ;

    if (environ == NULL)
        return NULL;

    /*
     * prefix length is to avoid return PATH=/HOME/BIN/ ONLY  /HOME/BIN
     */
    for (; *env_var; env_var++)
    {

        if ((*env_var)[0] == 'O' && (*env_var)[1] == 'L' && (*env_var)[2] == 'D' && (*env_var)[3] == 'P'
         && (*env_var)[4] == 'W' && (*env_var)[5] == 'D')
        {
            int path_len = _strlen(*env_var) + 1;
            paths = (char *)malloc(sizeof(char) * (path_len - prefix_len));
            _strcpy(paths, *(env_var) + prefix_len);
        }
    }
    return (paths);
}