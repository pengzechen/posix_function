#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用realloc()函数

int main() {
    // 初始化一个动态分配的内存块，大小为10个int类型
    int *ptr = (int*)malloc(10 * sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "内存分配失败\n");
        return 1;
    }

    // 初始化内存块中的值
    for (int i = 0; i < 10; i++) {
        ptr[i] = i;
    }

    // 打印原始内存块的内容
    printf("原始内存块内容：");
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // 重新分配内存块的大小，使其变为原来的两倍
    ptr = (int*)realloc(ptr, 20 * sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "内存重新分配失败\n");
        free(ptr); // 释放之前的内存块
        return 1;
    }

    // 打印重新分配后的内存块内容
    printf("重新分配后的内存块内容：");
    for (int i = 0; i < 20; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // 释放动态分配的内存块
    free(ptr);

    return 0;
}
