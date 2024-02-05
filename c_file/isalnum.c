#include <stdio.h>
#include <ctype.h> // 包含ctype.h以使用isalnum()函数

int main() {
    // 测试字符
    char ch = 'a';

    // 使用isalnum()检查字符是否是字母或数字
    if (isalnum(ch)) {
        printf("字符 %c 是字母或数字。\n", ch);
    } else {
        printf("字符 %c 不是字母或数字。\n", ch);
    }

    return 0;
}
