#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> // 包含errno.h以使用errno

int main() {
    // 假设我们有一个错误代码
    int error_code = EIO; // 通常表示输入/输出错误

    // 定义一个缓冲区来存储错误消息
    char error_buffer[100];

    // 使用strerror_r()函数获取与error_code对应的错误消息，并将其复制到error_buffer中
    int result = strerror_r(error_code, error_buffer, sizeof(error_buffer) - 1);

    // 检查strerror_r()的返回值
    if (result == 0) {
        // 成功获取了错误消息
        printf("错误代码 %d: %s\n", error_code, error_buffer);
    } else {
        // 无法获取错误消息，可能是因为缓冲区太小
        printf("无法获取错误消息：%s\n", error_buffer);
    }

    // 清理内存（如果需要）
    // 在这个例子中，error_buffer是由strerror_r()直接填充的，所以不需要额外清理。

    return 0;
}
