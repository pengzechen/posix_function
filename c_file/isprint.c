#include <stdio.h>
#include <ctype.h> // 包含ctype.h以使用isprint()函数

int main() {
    // 测试字符
    char ch = 'A';

    // 使用isprint()检查字符是否是可打印字符
    if (isprint(ch)) {
        printf("字符 %c 是可打印字符。\n", ch);
    } else {
        printf("字符 %c 不是可打印字符。\n", ch);
    }

    return 0;
}
