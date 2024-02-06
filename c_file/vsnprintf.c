#include <stdio.h>
#include <stdarg.h>

void my_printf(char *str, ...) {
    char buffer[100];
    int len;
    va_list args;

    va_start(args, str);
    len = vsnprintf(buffer, sizeof(buffer), str, args);
    va_end(args);

    printf("Result: %s, length: %d\n", buffer, len);
}

int main() {
    my_printf("The answer is %d", 42);
    my_printf("My name is %s and my age is %d", "Alice", 25);

    return 0;
}


