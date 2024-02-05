#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("This program will terminate immediately with an abortion.\n");

    // 调用 abort() 函数终止程序
    abort();

    // 这段代码不会被执行
    printf("This message will not be printed.\n");

    return EXIT_SUCCESS;
}
