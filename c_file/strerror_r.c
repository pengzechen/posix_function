#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> // ����errno.h��ʹ��errno

int main() {
    // ����������һ���������
    int error_code = EIO; // ͨ����ʾ����/�������

    // ����һ�����������洢������Ϣ
    char error_buffer[100];

    // ʹ��strerror_r()������ȡ��error_code��Ӧ�Ĵ�����Ϣ�������临�Ƶ�error_buffer��
    int result = strerror_r(error_code, error_buffer, sizeof(error_buffer) - 1);

    // ���strerror_r()�ķ���ֵ
    if (result == 0) {
        // �ɹ���ȡ�˴�����Ϣ
        printf("������� %d: %s\n", error_code, error_buffer);
    } else {
        // �޷���ȡ������Ϣ����������Ϊ������̫С
        printf("�޷���ȡ������Ϣ��%s\n", error_buffer);
    }

    // �����ڴ棨�����Ҫ��
    // ����������У�error_buffer����strerror_r()ֱ�����ģ����Բ���Ҫ��������

    return 0;
}
