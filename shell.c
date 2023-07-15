#include "main.h"

int main()

{
  char * prompt = " ($) ";
  char * command;
  size_t command_size = 1024;
  int status;
  char* argv[2]; 

while(1) {
  write(0, prompt , 6);

  int command_len = getline(&command, &command_size, stdin);
  if (command_len == -1) {
      exit(EXIT_FAILURE);
    }
  command[command_len - 1] = '\0'; 
  // write(0, command, command_size);

  argv[0] = command;
  argv[1] = NULL;
  pid_t pid = fork();
  if (pid == 0) {
    int res = execve(command,argv, NULL);
    if (res == -1) perror("./hsh");
  }
  else {
    wait(&status);
  }

  }

  return (0);
}
