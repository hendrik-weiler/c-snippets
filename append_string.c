#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
    char *temp = NULL;
    if(*str == NULL) {
        temp = malloc(1);
        if(temp == NULL) {
            printf("Could not allocate memory in append function");
            exit(1);
        }
        *str = temp;
    }
    temp = realloc(*str, strlen(*str)+strlen(append_str)+1);
    if(temp == NULL) {
        printf("Could not reallocate memory in append function");
        exit(1);
    }
    *str = temp;
    strcat(*str, append_str);
}