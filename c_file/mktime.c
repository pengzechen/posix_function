#include <stdio.h>

#include <time.h> // ����time.h��ʹ��mktime()����



int main() {

    // ����һ���ṹ�������洢���ں�ʱ��

    struct tm timeinfo;



    // �������ں�ʱ��

    timeinfo.tm_year = 2023 - 1900; // ��ݣ�ע��1900��ȥ����Ϊtm�ṹ������Ǵ�1900�꿪ʼ�ģ�

    timeinfo.tm_mon = 3 - 1;       // �·ݣ�ע��3��ȥ����Ϊtm�ṹ������Ǵ�0��ʼ�ģ�

    timeinfo.tm_mday = 13;         // ����

    timeinfo.tm_hour = 10;         // Сʱ

    timeinfo.tm_min = 30;          // ����

    timeinfo.tm_sec = 0;           // ��



    // ʹ��mktime()��tm�ṹ���е����ں�ʱ��ת��Ϊ��1970��1��1������������

    time_t now = mktime(&timeinfo);



    // ��ӡת�����ʱ���

    printf("ʱ����ǣ�%ld\n", now);



    return 0;

}

