#include <stdio.h>
#include <ctype.h> // 包含ctype.h以使用ispunct()函数

int main() {
    // 测试字符
    char ch = '.';

    // 使用ispunct()检查字符是否是标点符号
    if (ispunct(ch)) {
        printf("字符 %c 是标点符号。\n", ch);
    } else {
        printf("字符 %c 不是标点符号。\n", ch);
    }

    return 0;
}
