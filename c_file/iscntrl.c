#include <stdio.h>
#include <ctype.h> // 包含ctype.h以使用iscntrl()函数

int main() {
    // 测试字符
    char ch = '\n'; // 换行符

    // 使用iscntrl()检查字符是否是控制字符
    if (iscntrl(ch)) {
        printf("字符 %c 是控制字符。\n", ch);
    } else {
        printf("字符 %c 不是控制字符。\n", ch);
    }

    return 0;
}
