#include "main.h"

int is_space(char *s) {
  while (*s != '\0') {
    if (!isspace((unsigned char)*s))
      return (0);
    s++;
  }
  return (1);
}
