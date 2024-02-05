#include <stdio.h>
#include <time.h>

int main() {
    // 获取当前的时间
    time_t now;
    now = time(NULL);

    // 将时间转换为结构体 tm
    struct tm *local;
    local = localtime(&now);

    // 打印当前的日期和时间
    printf("当前的日期和时间是：%d-%d-%d %d:%d:%d\n",
           local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
           local->tm_hour, local->tm_min, local->tm_sec);

    return 0;
}
