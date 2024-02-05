#include <stdio.h>
#include <time.h> // 包含time.h以使用difftime()函数

int main() {
    struct tm specified_time = {0}; // 定义一个tm结构体用于存储指定时间
    double time_difference; // 定义一个double变量用于存储时间差

    // 设置指定时间的年、月、日、时、分、秒
    specified_time.tm_year = 2023 - 1900; // 注意tm_year的值是从1900年开始的
    specified_time.tm_mon = 5 - 1; // tm_mon是从0开始的，所以5月是4
    specified_time.tm_mday = 15;
    specified_time.tm_hour = 10;
    specified_time.tm_min = 30;
    specified_time.tm_sec = 0;

    // 将指定时间转换为时间戳
    time_t specified_timestamp = mktime(&specified_time);

    if (specified_timestamp == -1) {
        fprintf(stderr, "指定的时间格式不正确\n");
        return 1;
    }

    // 获取当前时间的时间戳
    time_t current_timestamp = time(NULL);

    // 计算当前时间与指定时间之间的时间差
    time_difference = difftime(current_timestamp, specified_timestamp);

    // 打印时间差
    printf("当前时间与指定时间之间的时间差（秒）：%f\n", time_difference);

    return 0;
}
