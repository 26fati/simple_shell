#include  <stdio.h>
#include  <unistd.h>
#include  <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()

{
  char * prompt = "($) ";
  char * command;
  size_t command_size = 1024;
  int status;
  char* argv[2]; 
  char* envp[1];


while(1) {
  write(0, prompt , 5);

  getline(&command, &command_size, stdin);
  
  printf("\n");
  write(0, command, command_size);
  command[strcspn(command, "\n")] = '\0';
  printf("\n");


  argv[0] = command;
  argv[1] = NULL;
  envp[0] = NULL;
  pid_t pid = fork();
  printf("just called fork process id = %u\n", pid);
  if (pid == 0) {
    printf("insid child process \n");
    int res = execve(argv[0], argv, NULL);
    if (res == -1) perror("execve");
  }
  else {
    wait(&status);
    printf("hello form parent process \n");
  }

  }
}
