#include "main.h"

void setenv_command(char **environ, char **argv) {
    char * var = argv[1];
    char * value = argv[2];

    if (var && value) {
        if (search_env_var(environ, argv[1])) {
            printf("var already exist\n");
        }

        else {
            printf("ggod to go\n");
        }
    }else{
        printf("ooops\n");
    }
}

bool search_env_var(char **env, char *var_to_search)
{
  char **env_var;
  env_var = env;

  if (env == NULL) return false;

  for (; *env_var; env_var++)
  {
    if (index_of_substring(*env_var, var_to_search) == 0 ){
        return true;
    }
  }
  return false;
}


int index_of_substring(char *str, char *substr) {
    int str_len = strlen(str);
    int substr_len = strlen(substr);

    for (int i = 0; i <= str_len - substr_len; i++) {
        bool found = true;
        for (int j = 0; j < substr_len; j++) {
            if (str[i + j] != substr[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i; 
        }
    }

    return -1; 
}