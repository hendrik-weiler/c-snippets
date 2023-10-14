#include <stdlib.h>

/**
 * Frees memory allocations
 * 
 * @param ptr The pointer to free
*/
void freeMemory(void *ptr) {
    free(ptr);
    ptr = NULL;
}