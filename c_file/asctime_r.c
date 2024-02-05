#include <stdio.h>
#include <time.h> // 包含time.h以使用asctime_r()函数
#include <stdlib.h>#include <time.h>
int main() {
    time_t now;
    struct tm local;
    char time_buffer[26]; // 足够存放asctime_r()的输出

    // 获取当前时间
    time(&now);
    // 将时间转换为tm结构
    local = *localtime(&now);

    // 使用asctime_r()将tm结构转换为字符串，并存储在用户提供的缓冲区中
    if (asctime_r(&local, time_buffer) == NULL) {
        perror("asctime_r");
        return 1;
    }

    printf("当前时间（字符串形式）： %s\n", time_buffer);

    return 0;
}
