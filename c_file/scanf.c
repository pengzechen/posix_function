#include <stdio.h>

int main() {
    int num1, num2, num3;

    // 使用 scanf 读取用户输入的三个整数
    printf("Enter three integers separated by spaces: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // 计算总和并打印
    int sum = num1 + num2 + num3;
    printf("The sum of the three numbers is: %d\n", sum);

    // 程序正常退出
    return 0;
}
