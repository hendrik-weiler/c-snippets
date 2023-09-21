#include <stdlib.h>
#include <string.h>

/**
 * The split element for str_split
 */
typedef struct {
    int size;
    char**data;
} str_split_elm;

/**
 * Splits a string to an array through a seperator
 *
 * Example:
 * char *base = "hello {world} dolly {world} test";
 * str_split_elm *elm = str_split(base, "{");
 *
 * @param base_str The string to split
 * @param seperator The seperator
 * @return str_split_elm
 */
str_split_elm *str_split(char*base_str, char *seperator) {
    str_split_elm *elm = malloc(sizeof(str_split_elm));
    elm->data = NULL;
    elm->size = 0;
    size_t search_len = strlen(seperator);
    size_t len = strlen(base_str);
    char *new_str = NULL;
    int size = 0;

    for (int i = 0; i < len; ++i) {
        char *ch = malloc(sizeof(char)+1);
        *ch = base_str[i];

        if(base_str[i] == seperator[0]) {
            int found = 0;
            for (int j = 0; j < search_len; ++j) {
                if(base_str[i+j] == seperator[found]) {
                    found++;
                }
            }
            if(found == search_len) {
                size++;
                elm->data = realloc(elm->data,sizeof(char**)*size);
                elm->size = size;

                elm->data[size-1] = malloc(sizeof(char)*strlen(new_str));

                strcpy(elm->data[size-1], new_str);
                free(new_str);
                new_str = NULL;
                i += found-1;
            }
            continue;
        }
        append(&new_str, ch);

        if(i==len-1) {
            size++;
            elm->data = realloc(elm->data,sizeof(char**)*size);
            elm->size = size;

            elm->data[size-1] = malloc(sizeof(char)*strlen(new_str));

            strcpy(elm->data[size-1], new_str);
            free(new_str);
            new_str = NULL;
        }
    }
    return elm;
}