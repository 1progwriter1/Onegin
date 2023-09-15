#include <stdio.h>
#include "func.h"
#include <assert.h>
#include <sys/stat.h>
#include <errno.h>
#include "values.h"
#include <string.h>

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

    errno = 0;
    struct stat buf = {};
    stat(filename, &buf);

    return buf.st_size;
}


FILE *fileopen(const char *filename, const char *mode) {

    assert(filename);

    FILE *fn = fopen(filename, mode);

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
    data->filename = fileopen(filename, READ);
    data->NumOfWords = 0;
    data->NumOfStr = 0;

}

void PrintData(String *data, long long int NumOfStr) {

    assert(data);

    for (size_t i = 0; i < NumOfStr - 1; i++) {
        if (data[i].len == 0)
            continue;
        printf("%s\n", data[i].str);
    }
}

void PrintDataFile(String *data, long long int NumOfStr, const char *filename) {

    assert(data);

    FILE *fn = fileopen(filename, APPEND);

    for (size_t i = 0; i < NumOfStr - 1; i++) {
        if (data[i].len == 0)
            continue;
        fprintf(fn, "%s\n", data[i].str);
    }
    fprintf(fn, "\n");
    if (fclose(fn) != 0)
        fprintf(stderr, "File not closed\n");
}

int GetArgs(int argc, const char *argv[], struct Args *maindata) {

    maindata->reverse = 0;
    maindata->file = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--file") == 0)
            maindata->file = 1;

        else if (strcmp(argv[i], "--reverse") == 0)
            maindata->reverse = 1;

        else printf("Invalid argument %s\n", argv[i]);
    }
    return 1;
}

void cleanfile(const char *filename) {
    FILE *fn = fileopen(filename, WRITE);
}
