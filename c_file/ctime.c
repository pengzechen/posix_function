#include <stdio.h>

#include <time.h> 

int main() {

    char *current_time = ctime(NULL);

    if (current_time != NULL) {

        printf("��ǰʱ�䣺 %s", current_time);

    } else {

        fprintf(stderr, "��ȡ��ǰʱ��ʧ��\n");

    }

    return 0;

}

