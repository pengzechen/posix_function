#include <stdio.h>
#include <time.h> // 包含time.h以使用localtime()函数

int main() {
    // 获取当前时间的time_t值
    time_t now;
    now = time(NULL);

    // 将time_t值转换为本地时间的struct tm指针
    struct tm *local_time;
    local_time = localtime(&now);

    // 打印本地时间
    printf("本地时间是：%s\n", asctime(local_time));

    return 0;
}
