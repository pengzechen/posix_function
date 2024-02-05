#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // ����������һ���������
    int error_code = 123;

    // ʹ��strerror()������ȡ��error_code��Ӧ�Ĵ�����Ϣ
    char *error_message = strerror(error_code);

    // ���error_messageΪNULL��˵��strerror()�޷��ҵ���error_code��Ӧ�Ĵ�����Ϣ
    if (error_message == NULL) {
        printf("�޷��ҵ�������Ϣ��\n");
    } else {
        // ��ӡ������Ϣ
        printf("������� %d: %s\n", error_code, error_message);
    }

    // �����ڴ棨�����Ҫ��
    free(error_message);

    return 0;
}
