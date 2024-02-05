#include <stdio.h>
#include <ctype.h> // 包含ctype.h以使用islower()函数

int main() {
    // 测试字符
    char ch = 'a';

    // 使用islower()检查字符是否是英文小写字母
    if (islower(ch)) {
        printf("字符 %c 是英文小写字母。\n", ch);
    } else {
        printf("字符 %c 不是英文小写字母。\n", ch);
    }

    return 0;
}
