#include <stdio.h>

int main() {
    // 设置标准输出的缓冲区为行缓冲区
    setbuf(stdout, NULL);

    // 打印一些文本，观察缓冲区的行为
    printf("This is the first line.\n");
    fflush(stdout); // 刷新输出缓冲区，确保文本立即显示
    sleep(1); // 等待1秒，观察文本是否立即显示

    // 取消标准输出的缓冲区设置
    setbuf(stdout, (char *)NULL);

    // 再次打印一些文本，观察缓冲区的行为
    printf("This is the second line.\n");
    fflush(stdout); // 刷新输出缓冲区，确保文本立即显示

    // 程序正常退出
    return 0;
}
