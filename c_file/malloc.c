#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用malloc()函数

int main() {
    // 分配一个int类型的内存块
    int *ptr = (int *)malloc(sizeof(int));

    // 检查分配是否成功
    if (ptr == NULL) {
        perror("内存分配失败");
        return 1;
    }

    // 给分配的内存块赋值
    *ptr = 42;

    // 打印分配的内存块的值
    printf("分配的内存块的值是：%d\n", *ptr);

    // 释放分配的内存
    free(ptr);

    return 0;
}
