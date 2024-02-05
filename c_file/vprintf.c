#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    char *ptr;
    int length;
    long count;

    // 读取用户输入的字符串
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin); // 使用 fgets 以避免读取换行符

    // 去除字符串末尾的换行符
    input[strcspn(input, "\n")] = '\0';

    // 计算字符串长度
    length = strlen(input);

    // 计算字符数（包括空白字符）
    count = 0;
    for (ptr = input; *ptr; ptr++) {
        count++;
    }

    // 使用 vprintf 打印用户输入的字符串、字符数和字符串长度
    vprintf("You entered: %s\n", input);
    vprintf("The number of characters (including spaces) is: %ld\n", count);
    vprintf("The length of the string is: %d\n", length);

    // 程序正常退出
    return 0;
}
