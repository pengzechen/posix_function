#include <stdio.h>
#include <ctype.h> // 包含ctype.h以使用isxdigit()函数

int main() {
    // 测试字符
    char ch = 'A';

    // 使用isxdigit()检查字符是否是十六进制数字
    if (isxdigit(ch)) {
        printf("字符 %c 是十六进制数字。\n", ch);
    } else {
        printf("字符 %c 不是十六进制数字。\n", ch);
    }

    return 0;
}
