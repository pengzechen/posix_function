#include <stdio.h>

#include <stdlib.h> 


int main() {

    int *ptr = (int*)malloc(sizeof(int));

    if (ptr == NULL) {

        fprintf(stderr, "malloc error\n");

        return 1;

    }

    *ptr = 42;

    printf("*ptr: %d\n", *ptr);

    free(ptr);

    return 0;

}

