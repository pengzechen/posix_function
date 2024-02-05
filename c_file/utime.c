#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <utime.h>

int main() {
    // �ļ����������������һ����Ϊ "example.txt" ���ļ�
    const char *filename = "example.txt";

    // ��ȡ��ǰʱ�䣬������ת��Ϊ struct timeval ��ʽ
    time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);
    struct timeval tv;
    tv.tv_sec = mktime(local_time); // �� struct tm ת��Ϊ��
    tv.tv_usec = 0; // ΢�벿������Ϊ0

    // �����ļ��ķ��ʺ��޸�ʱ��Ϊ��ǰʱ��
    if (utime(filename, &tv) != 0) {
        perror("utime() failed");
        return EXIT_FAILURE;
    }

    printf("The access and modification times of %s have been updated successfully.\n", filename);

    return EXIT_SUCCESS;
}
