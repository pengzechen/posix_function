#include <fenv.h>
#include <math.h>
#include <stdio.h>

#pragma STDC FENV_ACCESS ON

void showExceptions(void)
{
    printf("Exceptions: ");
    /*判断是否设置浮点异常。*/
    if(fetestexcept(FE_ALL_EXCEPT)==0)
    {
        puts("No floating-point status flag is set.");
    }
    else
    {
    	/*判断设置的浮点异常。*/
        if(fetestexcept(FE_DIVBYZERO))
            printf("FE_DIVBYZERO ");
        if(fetestexcept(FE_INEXACT))
            printf("FE_INEXACT ");
        if(fetestexcept(FE_INVALID))
            printf("FE_INVALID ");
        if(fetestexcept(FE_OVERFLOW))
            printf("FE_OVERFLOW ");
        if(fetestexcept(FE_UNDERFLOW))
            printf("FE_UNDERFLOW ");
        puts("");
    }
}

int main(void)
{
    fexcept_t flagp;

    feclearexcept(FE_ALL_EXCEPT);
    double result = exp(-1000.0);
    showExceptions();
    fegetexceptflag(&flagp,FE_ALL_EXCEPT);

    feclearexcept(FE_ALL_EXCEPT);
    fesetexceptflag(&flagp,FE_ALL_EXCEPT);
    showExceptions();

    return 0;
}