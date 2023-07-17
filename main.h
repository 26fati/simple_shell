#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdbool.h>


char *_strjoin(char *str1, char *str2); 
int _strlen(char *s);
void _trim(char* s);
int is_space(char *s);
char * _strcpy(char *dest, char *src);
char * _get_paths(char **env);
char **  _get_path_tokens(char *paths);
int file_exist(const char *file_path);
char *join(const char sep, const char *path1, const char *path2);

#endif
