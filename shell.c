#include "main.h"
extern char **environ;
int main()

{
  char *prompt = "($) ";
  char *command, *line, *token, **paths_arr;
  size_t command_size = 0;
  ssize_t command_len;
  char **argv, **s;
  char *delimiter = " \t\n";
  int i, count = 0;

  char *paths = _get_paths(environ);
  paths_arr = _get_path_tokens(paths);

  for (i = 0; i < 13; i++)
  {
    // printf("path[%d] = %s\n", i + 1, paths_arr[i]);
  }

  // for(i = 0 ; i < 13; i++) {
  //       char * full_path = join('/', paths_arr[i], "ls");
  //       printf("%s\n", full_path);

  //       if (file_exist(full_path)) printf("found exec on %d", i + 1);
  // }

  while (1)
  {
    write(0, prompt, 5);

    command_len = getline(&command, &command_size, stdin);
    if (command_len == -1)
    {
      exit(EXIT_SUCCESS);
    }
    /*
  command[command_len - 1] = '\0';

    _trim(command);

    //write(0, command, command_len);

  */
    if (is_space(command))
    {
      continue;
    }

    line = malloc(sizeof(char *) * command_len + 1);
    if (line == NULL)
      exit(EXIT_FAILURE);
    _strcpy(line, command);
    token = strtok(command, delimiter);

    while (token)
    {
      count++;
      token = strtok(NULL, delimiter);
    }

    count++;
    argv = malloc(sizeof(char *) * count);
    if (argv == NULL)
      exit(EXIT_FAILURE);
    token = strtok(line, delimiter);
    for (i = 0; token != NULL; i++)
    {
      argv[i] = malloc(sizeof(char) * _strlen(token) + 1);
      _strcpy(argv[i], token);
      token = strtok(NULL, delimiter);
    }
    argv[i] = NULL;
    free(line);

    if (file_exist(argv[0]))
    {

      if (fork() == 0)
      {
        if (execve(argv[0], argv, environ) == -1)
          perror("./hsh");
      }
      else
      {
        wait(NULL);
        for (i = 0; i < count; i++)
        {
          free(argv[i]);
        }
      }
    }
    else
    {
      // printf("file  does noext exist join operaion\n");
      for (i = 0; i < 13; i++)
      {
        char *full_path = join('/', paths_arr[i], argv[0]);
        // printf("%s\n", full_path);

        if (file_exist(full_path))
        {
          if (fork() == 0)
          {
            if (execve(full_path, argv, environ) == -1)
              perror("./hsh");
          }
          else
          {
            wait(NULL);
            for (i = 0; i < count; i++)
            {
              free(argv[i]);
            }
          }
          break;
        };
      }
    }
  }

  return (0);
}
