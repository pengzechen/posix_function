#include <stdio.h>
#include <ctype.h> // 包含toupper()函数

int main() {
    // 定义一个字符
    char ch = 'a';

    // 使用toupper()函数将字符转换为大写字母
    char upper_case = toupper(ch);

    // 打印转换后的大写字母
    printf("转换后的大写字母是：%c\n", upper_case);

    return 0;
}
