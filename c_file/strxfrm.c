#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main() {
    // 定义两个字符串
    char str1[] = "z";
    char str2[] = "a";

    // 获取当前的本地环境
    setlocale(LC_ALL, "");

    // 使用strxfrm()函数对字符串进行转换
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char *transformed1 = alloca(len1 + 1);
    char *transformed2 = alloca(len2 + 1);

    strxfrm(transformed1, str1, len1);
    strxfrm(transformed2, str2, len2);

    // 打印转换后的字符串
    printf("转换后的字符串1：%s\n", transformed1);
    printf("转换后的字符串2：%s\n", transformed2);

    // 比较两个转换后的字符串
    int result = strcmp(transformed1, transformed2);
    printf("比较结果：%d\n", result);

    return 0;
}
