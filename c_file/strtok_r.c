#include <stdio.h>

#include <string.h>


int main() {

    // ����һ����������ո�ָ����ʵ��ַ���

    char str[] = "Hello World This is a demo";



    // ʹ��strtok_r()�����ָ��ַ���

    char *token;

    char *save_ptr;

    int word_count = 0;



    // ��һ�ηָ�

    token = strtok_r(str, " ", &save_ptr);

    while (token != NULL) {

        // ��ӡ�ָ��ĵ���

        printf("���� %d: %s\n", word_count + 1, token);



        // ���±���ָ���λ��

        save_ptr = token;



        // �����ָ���һ������

        token = strtok_r(save_ptr, " ", &save_ptr);

        word_count++;

    }



    return 0;

}

