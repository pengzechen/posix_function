#include <stdio.h>



int main() {


    for (char character = 'A'; character <= 'Z'; ++character) {

        putchar_unlocked(character);

    }

    putchar_unlocked('\n');

    return 0;

}

