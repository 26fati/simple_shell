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
#include <errno.h>

extern char **environ;

char *_strjoin(char *str1, char *str2);
int _strlen(char *s);
int index_of_substring(char *str, char *substr);
int _atoi(char *s);
bool has_non_numerical_chars(char *str);
void _trim(char *s);
char **split_line(char *line);
int is_space(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_get_paths(char **env);
char **_get_path_tokens(char *paths);
int file_exist(const char *file_path);
char *join(const char sep, const char *path1, const char *path2);
int path_arr_length(char **path_arr);
char **tokenize_command(char *command, const char *delimiter, int *count);
void execute_command_directly(char **argv);
void try_execute_with_paths(char **argv, char **paths_arr,
int tokens_path_len);
void _printenv(char **envp);
void exit_command(char **argv);
int setenv_command(char *name, char *val, int overwrite);
char *_strchr(char *s, char c);
int unsetenv_command(char *name);
bool search_env_var(char **env, char *var_to_search);
int cd_command(char *path, char **environ);
int add_environment_variable(char ***environ, const char *new_var_value);
char *_get_home(char **environ);
char *_get_old_working_dir(char **environ);
void handle_builtin_commands(char **argv, char **environ,
bool *executed, char **paths_arr, char *paths, int tokens_path_len);
void cleanup_memory(char **argv, char **paths_arr, char *paths,
int tokens_path_len);
void cleanup_memory_no_argv(char **paths_arr, char *paths,
int tokens_path_len);
void exit_shell(void);
void free_cd(char *home, char *oldpwd);
int change_to_home_directory(char *buff, char *home, char *oldpwd);
void print_cd_error(char *path, char *oldpwd);
void cleanup_and_exit(char *command, char **paths_arr, char *paths,
int tokens_path_len);
#endif
