#include <stdio.h>
#include <time.h> // ����time.h��ʹ��difftime()����

int main() {
    struct tm specified_time = {0}; // ����һ��tm�ṹ�����ڴ洢ָ��ʱ��
    double time_difference; // ����һ��double�������ڴ洢ʱ���

    // ����ָ��ʱ����ꡢ�¡��ա�ʱ���֡���
    specified_time.tm_year = 2023 - 1900; // ע��tm_year��ֵ�Ǵ�1900�꿪ʼ��
    specified_time.tm_mon = 5 - 1; // tm_mon�Ǵ�0��ʼ�ģ�����5����4
    specified_time.tm_mday = 15;
    specified_time.tm_hour = 10;
    specified_time.tm_min = 30;
    specified_time.tm_sec = 0;

    // ��ָ��ʱ��ת��Ϊʱ���
    time_t specified_timestamp = mktime(&specified_time);

    if (specified_timestamp == -1) {
        fprintf(stderr, "ָ����ʱ���ʽ����ȷ\n");
        return 1;
    }

    // ��ȡ��ǰʱ���ʱ���
    time_t current_timestamp = time(NULL);

    // ���㵱ǰʱ����ָ��ʱ��֮���ʱ���
    time_difference = difftime(current_timestamp, specified_timestamp);

    // ��ӡʱ���
    printf("��ǰʱ����ָ��ʱ��֮���ʱ���룩��%f\n", time_difference);

    return 0;
}
