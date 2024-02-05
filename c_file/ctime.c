#include <stdio.h>
#include <time.h> // 包含time.h以使用ctime()函数

int main() {
    char *current_time = ctime(NULL);

    if (current_time != NULL) {
        // 打印当前时间的日期和时间
        printf("当前时间： %s", current_time);
    } else {
        fprintf(stderr, "获取当前时间失败\n");
    }

    return 0;
}
