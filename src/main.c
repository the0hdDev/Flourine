#include <stdio.h>
#include "lexer.h"

int main(int argc, char *argv[]) {
    char *file = readFile();
    printf("%s\n", file);
}

