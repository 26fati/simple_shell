#include "main.h"

void execute_command_directly(char **argv) {

    int state;
    pid_t pid;

    pid = fork();

    if (pid == -1)
    {
        exit(EXIT_FAILURE);
    }

    else if (pid == 0)
    {
        if (execve(argv[0], argv, environ) == -1)
        {
            perror("./hsh");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        if (waitpid(pid, &state, 0) == -1)
		{
			perror("waitpid");
		}
    }
}


void try_execute_with_paths(char **argv, char **paths_arr, int tokens_path_len) {

  for (int i = 0; i < tokens_path_len; i++) {
    char *full_path = join('/', paths_arr[i], argv[0]);
    if (file_exist(full_path)) {
      if (fork() == 0) {
        if (execve(full_path, argv, environ) == -1)
          perror("./hsh");
      } else {
        wait(NULL);
      }
      free(full_path);
      return; // Exit the function if the command was found and executed.
    }
    free(full_path);
  }
  
  // If the command is not found in any path, display an error message.
  write(2, "./hsh: 1: ", 10); 
  write(2, argv[0], _strlen(argv[0]));
  write(2, ": not found\n", 12);
  exit(127);
}






