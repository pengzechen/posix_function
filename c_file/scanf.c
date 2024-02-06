#include <stdio.h>



int main() {

    int num1, num2, num3;


    printf("Enter three integers separated by spaces: ");

    scanf("%d %d %d", &num1, &num2, &num3);

    int sum = num1 + num2 + num3;

    printf("The sum of the three numbers is: %d\n", sum);


    return 0;

}

