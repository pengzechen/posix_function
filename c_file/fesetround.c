#include <stdio.h>

#include <fenv.h> 

int main() {

    fenv_t env;

    fesetround(FE_TONEAREST);

    fegetenv(&env);

    printf("get env\n");

    fesetround(FE_UPWARD); 

    fegetenv(&env);

    printf("get env\n");



    return 0;

}

