#include <stdio.h>
#include <stdarg.h>

void myPtintf(char *format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}
int main()
{
    myPtintf("自定义printf函数：hello world\n");
    myPtintf("自定义printf函数：%s %s\n", "hello world", "C语言教程-猿说编程");
    printf("系统printf函数：hello world\n");
    printf("系统printf函数：%s %s\n", "hello world", "C语言教程-猿说编程");
    return(0);
}


