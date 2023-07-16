#include "main.h"
extern char **environ;
int main()

{
  char * prompt = "($) ";
  char * command, *line, *token;
  size_t command_size = 0;
  ssize_t command_len;
  char **argv;
  char *delimiter = " \t\n";
  int i, count = 0;

while(1) {
  write(0, prompt , 5);

  command_len = getline(&command, &command_size, stdin);
  if (command_len == -1) {
      exit(EXIT_SUCCESS);
  }
  /*
command[command_len - 1] = '\0';

  _trim(command);

  if (is_space(command)) {
  	continue;
  }
  //write(0, command, command_len);

*/
line = malloc(sizeof(char *) * command_len);
if (line == NULL)
	exit(EXIT_FAILURE);
_strcpy(line, command);
token = strtok(command, delimiter);
while(token)
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
  if (fork() == 0) 
  {
	  if (execve(argv[0], argv, environ) == -1)
			  perror("./hsh");
  }
  else {
    wait(NULL);
    for (i = 0; i < count; i++)
    {
        free(argv[i]);
    }
  }

  }

  return (0);
}
