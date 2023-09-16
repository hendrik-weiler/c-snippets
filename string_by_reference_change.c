#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 7

/**
 * Changes the string value by reference
 *
 * @param indexes The pointer to the string
 */
void change(char **indexes) {
    printf("%s\n", *indexes);
    char *newStr = malloc(sizeof(char)*strlen(*indexes));
    strcpy(newStr, *indexes);
    for (int i = 0; i < 4; ++i) {
        printf("%c ", newStr[i]);
    }
    free(newStr);
    *indexes = "zdsa";
}

int main() {

    int arr[] = {1,3,4,7,9,10,12};
    char *test = "asdd";

    // give pointer of the test variable to the change function
    change(&test);
    for (int i = 0; i < 4; ++i) {
        printf("%c ", test[i]);
    }
    return 0;
}
