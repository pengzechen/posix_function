#include <stdio.h>

#include <string.h>



int main() {

    char str[] = "Hello World This is a demo";

    char *words[10];

    int word_count = 0;

    char *token = strtok(str, " ");

    while (token != NULL) {

        words[word_count++] = token;

        token = strtok(NULL, " ");

    }

    for (int i = 0; i < word_count; i++) {

        printf("key, value %d: %s\n", i + 1, words[i]);

    }

    return 0;

}

