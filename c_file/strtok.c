#include <stdio.h>
#include <string.h>

int main() {
    // ����һ����������ո�ָ����ʵ��ַ���
    char str[] = "Hello World This is a demo";

    // ��ʼ��һ���ַ����������洢�ָ��ĵ���
    char *words[10];
    int word_count = 0;

    // ʹ��strtok()�����ָ��ַ���
    char *token = strtok(str, " ");
    while (token != NULL) {
        // ���ָ��ĵ��ʴ洢��������
        words[word_count++] = token;

        // �����ָ���һ������
        token = strtok(NULL, " ");
    }

    // ��ӡ�ָ��ĵ�������
    for (int i = 0; i < word_count; i++) {
        printf("���� %d: %s\n", i + 1, words[i]);
    }

    return 0;
}
