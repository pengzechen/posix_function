#include <stdio.h>
#include <ctype.h> // 包含ctype.h以使用isgraph()函数

int main() {
    // 测试字符
    char ch = 'A';

    // 使用isgraph()检查字符是否是图形字符
    if (isgraph(ch)) {
        printf("字符 %c 是图形字符。\n", ch);
    } else {
        printf("字符 %c 不是图形字符。\n", ch);
    }

    return 0;
}
