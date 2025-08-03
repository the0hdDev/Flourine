#include <stdio.h>
#include "lexer.h"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        perror("Incorrect number of arguments!");
        return EXIT_FAILURE;
    }

    printf("%s\n", argv[1]);

    char *file = readFile(argv[1]);
    printf("%s\n", file);
    return EXIT_SUCCESS;
}

