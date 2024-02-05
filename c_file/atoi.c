#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用atoi()函数

int main() {
    char str[] = "1234"; // 定义一个包含数字的字符串
    int value;

    // 使用atoi()函数将字符串转换为整数
    value = atoi(str);

    printf("转换后的整数： %d\n", value);

    return 0;
}
