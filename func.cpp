#include <stdio.h>
#include "func.h"
#include <assert.h>
#include <sys/stat.h>
#include <errno.h>
#include "values.h"

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int max(int a, int b) {
    return a >= b ? a : b;
}

long long int filelen(const char *filename) {

    assert(filename);

    struct stat buf = {};
    stat(filename, &buf);

    return buf.st_size;
}


FILE *fileopen(const char *filename) {

    assert(filename);

    FILE *fn = fopen(filename, "r");

    errno = 0;
    if (fn == NULL)
        perror("");

    return fn;
}

int min(int a, int b) {
    return a > b ? a : b;
}

long long int NumOfStr(const char *str, size_t len) {

    int c = 0, col = 1;
    for (size_t i = 0; i < len; i++) {
        if (str[i] == '\n')
            col++;
    }
    return col;
}

void SetStructText(struct Text *data, const char *filename) {

    data->filelen = filelen(filename);
    data->filename = fileopen(filename);
    data->NumOfWords = 0;
    data->NumOfStr = 0;
}

void PrintData(struct String **data, long long int NumOfStr) {

    assert(data);

    for (size_t i = 0; i < NumOfStr; i++)
        printf("%s\n", data[i]->str);
}
