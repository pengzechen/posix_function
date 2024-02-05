#include <stdio.h>
#include <ctype.h> // 包含ctype.h以使用isdigit()函数

int main() {
    // 测试字符
    char ch = '5';

    // 使用isdigit()检查字符是否是十进制数字
    if (isdigit(ch)) {
        printf("字符 %c 是十进制数字。\n", ch);
    } else {
        printf("字符 %c 不是十进制数字。\n", ch);
    }

    return 0;
}
