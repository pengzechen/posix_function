#include <stdio.h>
#include <stdarg.h> // 包含va_arg()和va_start()函数

int sum_of_numbers(int count, ...) {
    va_list args; // 声明变量参数列表
    va_start(args, count); // 初始化变量参数列表

    int sum = 0;
    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int); // 获取下一个参数
        sum += num;
    }

    va_end(args); // 清理变量参数列表
    return sum;
}

int main() {
    int result = sum_of_numbers(3, 1, 2, 3); // 调用函数并传递参数
    printf("The sum is: %d\n", result); // 打印结果
    return 0;
}
