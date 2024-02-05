#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用calloc()函数

int main() {
    int n = 10; // 定义要分配的元素数量
    int *array; // 定义指针变量用于存储分配的内存地址

    // 使用calloc()分配内存
    array = (int*)calloc(n, sizeof(int));

    if (array == NULL) {
        fprintf(stderr, "内存分配失败\n");
        return 1;
    }

    // 打印分配的内存地址
    printf("分配的内存地址： %p\n", array);

    // 释放分配的内存
    free(array);

    return 0;
}
