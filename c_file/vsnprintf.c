#include <stdio.h>
#include <stdarg.h> // 包含vsnprintf()函数

int main() {
    char buffer[100]; // 创建一个足够大的缓冲区

    // 使用vsnprintf格式化字符串
    vsnprintf(buffer, sizeof(buffer), "Hello, %s!", "World");

    // 打印结果
    printf("%s\n", buffer);

    return 0;
}
