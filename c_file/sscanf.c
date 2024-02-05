#include <stdio.h>
#include <stdlib.h> // 包含stdlib.h以使用malloc()函数

int main() {
    char input[100];
    int num;
    float floatnum;

    // 提示用户输入一个字符串
    printf("请输入一个包含整数和浮点数的字符串：");
    fgets(input, sizeof(input), stdin);

    // 去除输入字符串的换行符
    input[strcspn(input, "\n")] = '\0';

    // 使用sscanf()从字符串中解析出整数和浮点数
    sscanf(input, "%d %f", &num, &floatnum);

    // 打印解析出的整数和浮点数
    printf("整数是：%d\n", num);
    printf("浮点数是：%f\n", floatnum);

    return 0;
}
