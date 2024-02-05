#include <stdio.h>
#include <time.h> // 包含time.h以使用localtime_r()函数

int main() {
    // 获取当前时间的time_t值
    time_t now;
    now = time(NULL);

    // 分配内存用于struct tm结构体
    struct tm *local_time;
    local_time = (struct tm *)malloc(sizeof(struct tm));
    if (local_time == NULL) {
        perror("内存分配失败");
        return 1;
    }

    // 将time_t值转换为本地时间的struct tm指针
    local_time = localtime_r(&now, local_time);

    // 检查转换是否成功
    if (local_time == NULL) {
        perror("localtime_r()转换失败");
        free(local_time);
        return 1;
    }

    // 打印本地时间
    printf("本地时间是：%s\n", asctime(local_time));

    // 释放分配的内存
    free(local_time);

    return 0;
}
