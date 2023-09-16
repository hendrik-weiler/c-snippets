#include <stdlib.h>
#include <string.h>

void append(char**str, char*append_str) {
    if(*str == NULL) *str = malloc(1);
    *str = realloc(*str, strlen(*str)+strlen(append_str)+1);
    strcat(*str, append_str);
}