#include "main.h"


void exit_command(char **argv) 
{
	int exit_status = 0;
        
        if (!argv[1]) exit(EXIT_SUCCESS);

        exit_status = _atoi(argv[1]); /* exit LAKJF134 */

        if (has_non_numerical_chars(argv[1]) || exit_status < 0) {
            write(2, "./hsh: 1: ", 10); 
            write(2, argv[0], _strlen(argv[0]));
            write(2, ": Illegal number: ", 18);
            write(2, argv[1], _strlen(argv[1]));
            write(2, "\n", 1);
            exit(2);
        }
        
        if (exit_status >= 0) exit(exit_status);    
}


bool has_non_numerical_chars(char *str) {
    while (*str != '\0') {
        if (*str < '0' || *str > '9') {
            return true;
        }
        str++;
    }
    return false;
}
