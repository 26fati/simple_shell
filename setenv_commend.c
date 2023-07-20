#include "main.h"

void setenv_command(char **argv) {
    char * var = argv[1];
    char * value = argv[2];

    printf("var = %s . value = %s \n", var, value);
}