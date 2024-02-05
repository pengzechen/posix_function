#include <stdio.h>
#include <time.h>

int main() {
    // 获取当前时间
    time_t now;
    struct tm *local;

    time(&now); // 使用time函数获取当前时间戳
    local = localtime(&now); // 将时间戳转换为本地时间

    // 定义一个缓冲区来存储时间字符串
    char time_buffer[20];

    // 使用strftime()函数将时间转换为不同的格式
    // 例如， "%Y-%m-%d %H:%M:%S" 表示4位年份-%2位月份-%2位日期 %2位小时：%2位分钟：%2位秒
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", local);

    // 打印转换后的时间字符串
    printf("当前时间是：%s\n", time_buffer);

    return 0;
}
