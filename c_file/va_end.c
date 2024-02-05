#include <stdio.h>
#include <stdarg.h> // ����va_arg()��va_end()����

int add_numbers(int count, ...) {
    va_list args;
    va_start(args, count);

    int sum = 0;
    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        sum += num;
    }

    va_end(args); // ������������б�
    return sum;
}

int main() {
    int result = add_numbers(3, 1, 2, 3);
    printf("The sum is: %d\n", result);
    return 0;
}
