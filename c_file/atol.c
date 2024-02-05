#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用atol()函数

int main() {
    char str[] = "1234"; // 定义一个包含数字的字符串
    long value;

    // 使用atol()函数将字符串转换为长整型数
    value = atol(str);

    printf("转换后的长整数： %ld\n", value);

    return 0;
}
