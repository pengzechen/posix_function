#include <stdio.h>
#include <time.h> // 包含time.h以使用asctime()函数

int main() {
    time_t now;
    struct tm *local;

    // 获取当前时间
    time(&now);
    // 将时间转换为tm结构
    local = localtime(&now);

    // 使用asctime()将tm结构转换为字符串
    char *time_str = asctime(local);

    printf("当前时间（字符串形式）： %s\n", time_str);

    return 0;
}
