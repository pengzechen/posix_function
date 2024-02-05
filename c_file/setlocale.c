#include <stdio.h>
#include <locale.h> // 包含locale.h以使用setlocale()函数

int main() {
    // 设置区域设置为法语（法语法国）
    setlocale(LC_ALL, "fr_FR.UTF-8");

    // 打印当前日期
    printf("当前日期是：%s\n", strftime(NULL, 0, "%Y-%m-%d", localtime(NULL)));

    return 0;
}
