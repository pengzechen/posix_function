#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>



int main() {

    char temp_template[] = "/tmp/htp.XXXXXX";

    int fd = mkstemp(temp_template);

    FILE *file = fdopen(fd,"w");

    if (file == NULL) {

        perror("fopen() failed to open the file");

        close(fd);

        return EXIT_FAILURE;

    }

    const char *text = "Hello, World!\n";

    if (fputs(text, file) == EOF) {

        perror("fputs() failed to write to the file");

        fclose(file);

        close(fd);

        return EXIT_FAILURE;

    }

    if (fclose(file) != 0) {

        perror("fclose() failed to close the file");

        close(fd);

        return EXIT_FAILURE;

    }

    if (unlink(temp_template) != 0) {

        perror("unlink() failed to delete the file");

        close(fd);

        return EXIT_FAILURE;

    }

    close(fd);

    printf("File %s deleted successfully.\n", temp_template);


    return EXIT_SUCCESS;

}

