#include <stdio.h>
#include <time.h>
#include <unistd.h> // 包含setuid()函数

int main() {
    // 设置当前时区为中国标准时间（CST）
    setenv("TZ", "CST", 1);
    tzset();

    // 获取当前时区的名称
    char *timezone_name = tzname[0];

    // 打印当前时区的名称
    printf("当前时区名称：%s\n", timezone_name);

    return 0;
}
