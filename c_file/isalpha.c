#include <stdio.h>
#include <ctype.h> // 包含ctype.h以使用isalpha()函数

int main() {
    // 测试字符
    char ch = 'A';

    // 使用isalpha()检查字符是否是字母
    if (isalpha(ch)) {
        printf("字符 %c 是字母。\n", ch);
    } else {
        printf("字符 %c 不是字母。\n", ch);
    }

    return 0;
}
