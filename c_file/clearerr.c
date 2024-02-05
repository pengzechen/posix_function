#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    int ch;

    // 提示用户输入字符串
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // 检查是否有输入错误
    if (feof(stdin)) {
        printf("End of file reached.\n");
    } else if (ferror(stdin)) {
        perror("Read error");
    } else {
        // 打印输入的字符串
        printf("You entered: %s", input);
    }

    // 清除流中的错误标志
    clearerr(stdin);

    // 读取一个字符
    ch = getchar();

    // 检查是否有错误
    if (feof(stdin)) {
        printf("End of file reached after clearerr().\n");
    } else if (ferror(stdin)) {
        perror("Read error after clearerr().");
    } else {
        // 打印读取的字符
        printf("Read character: %c\n", ch);
    }

    return 0;
}
