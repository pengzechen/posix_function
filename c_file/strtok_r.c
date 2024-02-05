#include <stdio.h>
#include <string.h>

int main() {
    // 定义一个包含多个空格分隔单词的字符串
    char str[] = "Hello World This is a demo";

    // 使用strtok_r()函数分割字符串
    char *token;
    char *save_ptr;
    int word_count = 0;

    // 第一次分割
    token = strtok_r(str, " ", &save_ptr);
    while (token != NULL) {
        // 打印分割后的单词
        printf("单词 %d: %s\n", word_count + 1, token);

        // 更新保存指针的位置
        save_ptr = token;

        // 继续分割下一个单词
        token = strtok_r(save_ptr, " ", &save_ptr);
        word_count++;
    }

    return 0;
}
