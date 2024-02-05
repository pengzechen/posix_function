#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用qsort()函数

// 比较函数，用于qsort()
int compare(const void *a, const void *b) {
    const int *x = (const int *)a;
    const int *y = (const int *)b;

    // 如果x小于y，返回-1
    if (*x < *y) {
        return -1;
    }
    // 如果x等于y，返回0
    if (*x == *y) {
        return 0;
    }
    // 如果x大于y，返回1
    return 1;
}

int main() {
    // 定义一个整数数组
    int array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int n = sizeof(array) / sizeof(array[0]);

    // 使用qsort()对数组进行排序
    qsort(array, n, sizeof(int), compare);

    // 打印排序后的数组
    printf("排序后的数组是：");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
