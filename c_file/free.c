#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用free()函数

int main() {
    // 分配一些内存
    int *ptr = (int*)malloc(sizeof(int));

    if (ptr == NULL) {
        fprintf(stderr, "内存分配失败\n");
        return 1;
    }

    // 使用分配的内存
    *ptr = 42;
    printf("分配的内存中的值：%d\n", *ptr);

    // 释放内存
    free(ptr);

    // 再次尝试访问内存以确保它已被释放
    // 这将打印出一个错误消息，因为内存已被释放
    // printf("尝试访问已释放的内存：%d\n", *ptr);

    return 0;
}
