#include <stdio.h>
#include <setjmp.h>

// 定义一个长跳转的缓冲区
jmp_buf main_buffer;

// 声明一个函数，用于演示setjmp和longjmp
void do_longjmp(void) {
    printf("进入 do_longjmp 函数\n");
    // 使用 longjmp 返回到 setjmp 设置的地方
    longjmp(main_buffer, 1);
    printf("这是 do_longjmp 中的代码，但不会被执行\n");
}

int main() {
    // 设置一个跳跃点
    if (!setjmp(main_buffer)) {
        printf("第一次调用 do_longjmp 之前\n");
        // 调用 do_longjmp，它会使用 longjmp 跳转回来
        do_longjmp();
        printf("这是 main 函数中的代码，但在 longjmp 之后不会被执行\n");
    } else {
        printf("回到 main 函数\n");
    }

    return 0;
}
