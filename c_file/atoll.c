#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用atoll()函数

int main() {
    char str[] = "1234"; // 定义一个包含数字的字符串
    long long value;

    // 使用atoll()函数将字符串转换为长长整型数
    value = atoll(str);

    printf("转换后的长长整数： %lld\n", value);

    return 0;
}
