#include <stdio.h>
#include <time.h>

int main() {
    // ��ȡ��ǰʱ��
    time_t now;
    struct tm *local;

    time(&now); // ʹ��time������ȡ��ǰʱ���
    local = localtime(&now); // ��ʱ���ת��Ϊ����ʱ��

    // ����һ�����������洢ʱ���ַ���
    char time_buffer[20];

    // ʹ��strftime()������ʱ��ת��Ϊ��ͬ�ĸ�ʽ
    // ���磬 "%Y-%m-%d %H:%M:%S" ��ʾ4λ���-%2λ�·�-%2λ���� %2λСʱ��%2λ���ӣ�%2λ��
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", local);

    // ��ӡת�����ʱ���ַ���
    printf("��ǰʱ���ǣ�%s\n", time_buffer);

    return 0;
}
