#include <stdio.h>

int main() {
    // ���ñ�׼����Ļ�����Ϊ�л�����
    setbuf(stdout, NULL);

    // ��ӡһЩ�ı����۲컺��������Ϊ
    printf("This is the first line.\n");
    fflush(stdout); // ˢ�������������ȷ���ı�������ʾ
    sleep(1); // �ȴ�1�룬�۲��ı��Ƿ�������ʾ

    // ȡ����׼����Ļ���������
    setbuf(stdout, (char *)NULL);

    // �ٴδ�ӡһЩ�ı����۲컺��������Ϊ
    printf("This is the second line.\n");
    fflush(stdout); // ˢ�������������ȷ���ı�������ʾ

    // ���������˳�
    return 0;
}
