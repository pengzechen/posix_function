#include <stdio.h>
#include <setjmp.h>

// 定义一个长跳转的缓冲区
jmp_buf my_buffer;

// 声明一个函数，用于演示longjmp
void my_function(void) {
    printf("进入 my_function\n");
    // 使用 longjmp 返回到 setjmp 设置的地方
    longjmp(my_buffer, 1);
    printf("这是 my_function 中的代码，但不会被执行\n");
}

int main() {
    // 设置一个跳跃点
    if (!setjmp(my_buffer)) {
        printf("第一次调用 my_function 之前\n");
        // 调用 my_function，它会使用 longjmp 跳转回来
        my_function();
        printf("这是 main 函数中的代码，但在 longjmp 之后不会被执行\n");
    } else {
        printf("回到 main 函数\n");
    }

    return 0;
}
