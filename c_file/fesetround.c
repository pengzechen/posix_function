#include <stdio.h>
#include <fenv.h> // 包含fenv.h以使用fesetround()函数

int main() {
    fenv_t env;

    // 获取当前的舍入模式
    fesetround(FE_TONEAREST); // 假设当前舍入模式是FE_TONEAREST
    fegetenv(&env);
    printf("当前的舍入模式：FE_TONEAREST\n");

    // 设置新的舍入模式
    fesetround(FE_UPWARD); // 设置舍入模式为FE_UPWARD

    // 验证新的舍入模式是否生效
    fegetenv(&env);
    printf("新的舍入模式：FE_UPWARD\n");

    return 0;
}
