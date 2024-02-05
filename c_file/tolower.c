#include <stdio.h>
#include <ctype.h> // 包含tolower()函数

int main() {
    // 定义一个字符
    char ch = 'A';

    // 使用tolower()函数将字符转换为小写字母
    char lower_case = tolower(ch);

    // 打印转换后的小写字母
    printf("转换后的小写字母是：%c\n", lower_case);

    return 0;
}
