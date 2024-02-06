#include <stdio.h>

#include <stdlib.h> 

int main() {

    int *ptr = (int*)malloc(10 * sizeof(int));

    if (ptr == NULL) {

        fprintf(stderr, "malloc error\n");

        return 1;

    }


    for (int i = 0; i < 10; i++) {

        ptr[i] = i;

    }


    printf("old");

    for (int i = 0; i < 10; i++) {

        printf("%d ", ptr[i]);

    }

    printf("\n");


    ptr = (int*)realloc(ptr, 20 * sizeof(int));

    if (ptr == NULL) {

        fprintf(stderr, "realloc error\n");

        free(ptr); 

        return 1;

    }

    printf("new");

    for (int i = 0; i < 20; i++) {

        printf("%d ", ptr[i]);

    }

    printf("\n");

    free(ptr);

    return 0;

}

