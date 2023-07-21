#include "main.h"

/**
 * tokenize_command - searches for PATH in ENVIRON global variable.
 *
 * @env: pointer to global var environ.
 *
 * Return: string containing the PATH`.
 */
char **tokenize_command(char *command, const char *delimiter, int *count)
{
  char *line, *token;
  char **argv;
  int i;

  /* Allocate memory for line */
  line = malloc(sizeof(char *) * (strlen(command) + 1));
  if (line == NULL)
  {
    perror("Memory allocation error");
    exit(EXIT_FAILURE);
  }
  strcpy(line, command);

  /* Count the number of tokens */
  *count = 0;
  token = strtok(line, delimiter);
  while (token)
  {
    (*count)++;
    token = strtok(NULL, delimiter);
  }

  /* Allocate memory for argv array */
  argv = malloc(sizeof(char *) * (*count + 1));
  if (argv == NULL)
  {
    perror("Memory allocation error");
    exit(EXIT_FAILURE);
  }

  /* Copy tokens into argv array */
  token = strtok(command, delimiter);
  for (i = 0; token != NULL; i++)
  {
    argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
    if (argv[i] == NULL)
    {
      perror("Memory allocation error");
      exit(EXIT_FAILURE);
    }
    strcpy(argv[i], token);
    token = strtok(NULL, delimiter);
  }
  argv[i] = NULL;

  /* Free the memory allocated for line */
  free(line);

  return (argv);
}
