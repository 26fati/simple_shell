#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdbool.h>
#include <errno.h>


extern char **environ;

char *_strcpy(char *dest, char *src);
char **read_line(void);
char *_getenv(const char *name);
char *locate(const char *name);
char *join(const char sep, const char *path1, const char *path2);
int file_exist(const char *filePath);
char *_strdup(char *str);
bool handle_builtin(char **args);
int _strcmp(char *s1, char *s2);
int env_func(char **args);
int _strlen(char *s);
int _atoi(char *s);
void free_grid(char **grid, int height);
void exit_func(char **args);
#endif
