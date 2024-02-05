#include <stdio.h>
#include <string.h>

int main() {
    // 定义一个包含多个空格分隔单词的字符串
    char str[] = "Hello World This is a demo";

    // 初始化一个字符串数组来存储分割后的单词
    char *words[10];
    int word_count = 0;

    // 使用strtok()函数分割字符串
    char *token = strtok(str, " ");
    while (token != NULL) {
        // 将分割后的单词存储到数组中
        words[word_count++] = token;

        // 继续分割下一个单词
        token = strtok(NULL, " ");
    }

    // 打印分割后的单词数组
    for (int i = 0; i < word_count; i++) {
        printf("单词 %d: %s\n", i + 1, words[i]);
    }

    return 0;
}
