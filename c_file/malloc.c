#include <stdio.h>

#include <stdlib.h>

int main() {

    int *ptr = (int *)malloc(sizeof(int));

    if (ptr == NULL) {

        perror("err");

        return 1;

    }

    *ptr = 42;

    printf(" %d\n", *ptr);

    free(ptr);

    return 0;

}

