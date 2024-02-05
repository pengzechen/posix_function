#include <stdio.h>
#include <time.h>

int main() {
    // 获取当前时区的名称
    char *timezone_name = tzname[0];

    // 打印当前时区的名称
    printf("当前时区名称：%s\n", timezone_name);

    return 0;
}
