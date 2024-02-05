#include <inttypes.h>
#include <stdio.h>

int main(void)
{
    imaxdiv_t divResult;

    divResult = imaxdiv(10,3);
    printf("The quotient is %jd and the remainder is %jd.\n",
           divResult.quot, divResult.rem);

    return 0;
}
