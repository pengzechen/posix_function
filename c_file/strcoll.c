#include <stdio.h>
#include <locale.h> // 包含locale.h以使用setlocale()和strcoll()

int main() {
    // 设置程序使用的区域设置
    setlocale(LC_ALL, "en_US.UTF-8"); // 设置 locale 为美国英语

    // 定义两个字符串变量
    char str1[] = "Apple";
    char str2[] = "banana";

    // 使用strcoll()函数比较str1和str2
    int result = strcoll(str1, str2);

    // 检查比较结果
    if (result < 0) {
        // str1小于str2
        printf("str1 < str2\n");
    } else if (result > 0) {
        // str1大于str2
        printf("str1 > str2\n");
    } else {
        // str1等于str2
        printf("str1 == str2\n");
    }

    return 0;
}
