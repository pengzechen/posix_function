#include <stdio.h>
#include <math.h> // 包含math.h以使用abs()函数
#include <stdlib.h>
int main() {
    double num = -10.5; // 定义一个负数
    double abs_result = abs(num); // 使用abs()函数计算绝对值

    printf("原始数值： %f\n", num);
    printf("绝对值： %f\n", abs_result);

    return 0;
}
