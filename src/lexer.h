//
// Created by theow on 02.08.2025.
//

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef READFILE_H
#define READFILE_H

uint64_t getFileSize(FILE *file) {
    fseek(file, 0, SEEK_END);
    uint64_t size = ftell(file) + 1;
    fseek(file, 0, SEEK_SET);
    return size;
}

char* readFile(char* fileName[]) {
    FILE *mainFilePtr = fopen(fileName, "r");
    if (!mainFilePtr) {
        perror("File not found or cant be opened");
        return;
    }

    fseek(mainFilePtr, 0, SEEK_END);
    long mainFileSize = ftell(mainFilePtr);
    rewind(mainFilePtr);

    char *file = malloc(mainFileSize + 1);
    if (!file) {
        perror("memory allocation failed");
        fclose(mainFilePtr);
        return;
    }

    fread(file, 1, mainFileSize, mainFilePtr);
    file[mainFileSize] = '\0';

    fclose(mainFilePtr);

    return file;
    free(file);
}

#endif //READFILE_H
