#include <string.h>
#include <stdlib.h>

/**
 * Replaces all occurrences with a search string with another
 *
 * Example:
 * char *str = r.data;
 * str_replace(&str, "{exe}", EXEFILE);
 * str_replace(&str, "{data}", base_str);
 * str_replace(&str, "{time}", "placeholder");
 *
 * @param str The base string pointer
 * @param search The string to search
 * @param replace The string to replace
 */
void str_replace(char**str, char*search, char*replace) {
    size_t len = strlen(*str);
    size_t search_len = strlen(search);
    char *new_str = NULL;
    char *str_copy = calloc(len, sizeof(char));
    strcpy(str_copy, *str);
    for (int i = 0; i < len; ++i) {
        char *ch = malloc(sizeof(char)+1);
        *ch = str_copy[i];

        if(str_copy[i] == search[0]) {
            int found = 0;
            for (int j = 0; j < search_len; ++j) {
                if(str_copy[i+j] == search[found]) {
                    found++;
                }
            }
            if(found == search_len) {
                append(&new_str, replace);
                i += found-1;
                continue;
            }
        }

        append(&new_str, ch);
    }
    *str = new_str;
}