#include <stdio.h>
#include <ctype.h> // 包含ctype.h以使用isspace()函数

int main() {
    // 测试字符
    char ch = ' ';

    // 使用isspace()检查字符是否是空白字符
    if (isspace(ch)) {
        printf("字符 %c 是空白字符。\n", ch);
    } else {
        printf("字符 %c 不是空白字符。\n", ch);
    }

    return 0;
}
