#include <stdlib.h>
#include <string.h>

/**
 * Appends a string to another string
 * 
 * Example:
 * char* base_str = NULL;
 * append(&base_str, "my string to append");
 * 
 * @param str The char pointer array
 * @param append_str The string to append
*/
void append(char**str, char*append_str) {
    if(*str == NULL) *str = malloc(1);
    *str = realloc(*str, strlen(*str)+strlen(append_str)+1);
    strcat(*str, append_str);
}