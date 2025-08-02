//
// Created by theow on 02.08.2025.
//

#include <stdint.h>
#include <stdio.h>

#ifndef READFILE_H
#define READFILE_H

uint64_t getFileSize(FILE *file) {
    fseek(file, 0, SEEK_END);
    uint64_t size = ftell(file) + 1;
    fseek(file, 0, SEEK_SET);
    return size;
}

void readFile() {

    char fileName[] = "main.tlg";

    FILE *mainFilePtr = fopen(fileName,  "r");
    fseek(mainFilePtr, 0, SEEK_END);
    uint64_t mainFileSize = getFileSize(mainFilePtr);

    char file[mainFileSize];
    fgets(file, sizeof(file), mainFilePtr);

    fclose(mainFilePtr);
    printf("%s", file);

}

#endif //READFILE_H
