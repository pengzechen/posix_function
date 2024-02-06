#include <stdio.h>

#include <stdlib.h> 

int compare(const void *a, const void *b) {

    const int *x = (const int *)a;

    const int *y = (const int *)b;

    if (*x < *y) {

        return -1;

    }

    if (*x == *y) {

        return 0;

    }

    return 1;

}



int main() {

    int array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    int n = sizeof(array) / sizeof(array[0]);

    qsort(array, n, sizeof(int), compare);

    printf("qsort");

    for (int i = 0; i < n; i++) {

        printf("%d ", array[i]);

    }

    printf("\n");



    return 0;

}

