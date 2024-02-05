#include <stdio.h>
#include <time.h> // 包含time.h以使用gmtime_r()函数

int main() {
    time_t now = time(NULL); // 获取当前时间
    struct tm *gmt;

    // 使用gmtime_r()将当前时间转换为GMT时间
    gmt = gmtime_r(&now, &gmt);

    if (gmt == NULL) {
        perror("gmtime_r() 失败");
        return 1;
    }

    // 打印GMT时间
    printf("GMT时间：%d-%d-%d %d:%d:%d\n",
           gmt->tm_year + 1900, gmt->tm_mon + 1, gmt->tm_mday,
           gmt->tm_hour, gmt->tm_min, gmt->tm_sec);

    return 0;
}
