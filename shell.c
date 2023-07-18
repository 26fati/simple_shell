#include "main.h"




int main()
{
  // printf("before anything\n");
  char *prompt = "($) ";
  char *command, *line, *token, **paths_arr;
  size_t command_size = 0;
  ssize_t command_len;
  char **argv, **s;
  char *delimiter = " \t\n";
  int i, count = 0, tokens_path_len;
  char *paths = _get_paths(environ);
  bool is_path_empty = false;
  bool command_executed = true;
  paths_arr = _get_path_tokens(paths);
  tokens_path_len = path_arr_length(paths_arr);
  // printf("token path len %d\n", tokens_path_len);
  while (1)
  {
    write(0, prompt, 5);

    command_len = getline(&command, &command_size, stdin);
    
    if (command_len == -1)
    {
      exit(EXIT_SUCCESS);
    }

    if (is_space(command))
    {
      continue;
    }
    argv = tokenize_command(command, delimiter, &count);

    if (file_exist(argv[0]))
    {
      // printf("file exist\n");
      if (fork() == 0)
      {
        // printf("am here");
        if (execve(argv[0], argv, environ) == -1)
          perror("./hsh");
      }
      else
      {
        wait(NULL);
      }
    }
    else 
    {
      // printf("file  does noext exist join operaion\n");
      for (i = 0; i < tokens_path_len; i++)
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
            command_executed = false;
            // printf("executed\n");
            wait(NULL);
          }
          break;
        };
        free(full_path);
      }
      if(errno == ENOENT) {
        // perror("./hsh");
	write(2, "./hsh: 1: ls: not found\n", 24); 
        exit(127);
      }
      
    }

    for (i = 0; i < count; i++)
    {
          free(argv[i]);
    }
  }

  return (0);
}
