#include "main.h"

int main()

{
  char * prompt = "($) ";
  char * command;
  size_t command_size = 0;
  ssize_t command_len;
  char *argv[2];

while(1) {
  write(0, prompt , 5);

  command_len = getline(&command, &command_size, stdin);
  if (command_len == -1) {
      exit(EXIT_FAILURE);
    }


  command[command_len - 1] = '\0';


  write(0, command, command_len);


  argv[0] = command;
  argv[1] = NULL;
  if (fork() == 0) 
  {
	  if (execve(argv[0], argv, NULL) == -1)
			  perror("./hsh");
  }
  else {
    wait(NULL);
  }

  }

  return (0);
}
