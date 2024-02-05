#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // 假设我们有一个错误代码
    int error_code = 123;

    // 使用strerror()函数获取与error_code对应的错误消息
    char *error_message = strerror(error_code);

    // 如果error_message为NULL，说明strerror()无法找到与error_code对应的错误消息
    if (error_message == NULL) {
        printf("无法找到错误消息。\n");
    } else {
        // 打印错误消息
        printf("错误代码 %d: %s\n", error_code, error_message);
    }

    // 清理内存（如果需要）
    free(error_message);

    return 0;
}
