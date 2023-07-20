#include "main.h"

void execute_command_directly(char **argv) {

    int status;
    pid_t pid;

    // printf("execute_command_directly\n");
    pid = fork();

    if (pid == -1)
    {
        exit(EXIT_FAILURE);
    }

    else if (pid == 0)
    {
        printf("test pid  = 0\n");
        if (execve(argv[0], argv, environ) == -1)
        {
            perror("./hsh");
            // exit(EXIT_FAILURE);
        }
        // printf("a;dslkfjaslkf\n");
    }
    else
    {
        int res = waitpid(pid, &status, 0);
        // printf("state = %d\n", status);
        if (res == -1)
		{
			perror("waitpid");
		}

        if(WIFEXITED(status)) {

            _exit(2);
        };
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






