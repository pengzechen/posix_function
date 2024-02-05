#include <inttypes.h>
#include <stdio.h>

int main(void)
{
    intmax_t a = -5;

    printf("Absolute value of a:%jd.", imaxabs(a));

    return 0;
}

