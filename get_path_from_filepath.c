#include <string.h>

/**
 * Gets the directory path from a file path
 *
 * @param filepath The file path
 * @return The directory path
 */
char *get_path_from_filepath(char *filepath) {
    int last_slash = 0;
    for(int i = 0; i < strlen(filepath); ++i) {
        if(filepath[i] == '/') {
            last_slash = i;
        }
    }
    char *path = calloc(last_slash, sizeof(char));
    for (int i = 0; i < last_slash; ++i) {
        char *ch = malloc(2);
        ch[0] = filepath[i];
        ch[1] = '\0';
        strcat(path, ch);
        free(ch);
    }
    return path;
}