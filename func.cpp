#include <stdio.h>
#include "func.h"
#include <assert.h>
#include <sys/stat.h>

int max(int a, int b) {
    return a >= b ? a : b;
}

long long int filelen(const char *filename) {

    assert(filename);

    struct stat buf = {};
    stat("uncle.txt", &buf);

    return buf.st_size;
}


FILE *fileopen(const char *filename) {
    return fopen(filename, "r");
}

long long int NumOfStr(FILE *filename) {

    assert(filename);

    long long int num = 0;
    int c = 0;

    while ((c = getc(filename)) != EOF)
        if (c == '\n')
            num++;

    return num;
}

void freeall(char *data, char *buf) {
    free(data);
    free(buf);
}

int min(int a, int b) {
    return a > b ? a : b;
}
