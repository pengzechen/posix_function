#include <stdio.h>
#include <ctype.h> // 包含ctype.h以使用isupper()函数

int main() {
    // 测试字符
    char ch = 'A';

    // 使用isupper()检查字符是否是英文大写字母
    if (isupper(ch)) {
        printf("字符 %c 是英文大写字母。\n", ch);
    } else {
        printf("字符 %c 不是英文大写字母。\n", ch);
    }

    return 0;
}
