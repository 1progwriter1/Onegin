#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "func.h"
#include "values.h"

void swapptr(char *a, char *b) {

    char *temp = a;
    a = b;
    b = temp;
}

void swapwords(char *a, char *b, const int rows) {

    assert(a);
    assert(b);

    int *pt1 = (int *) a;
    int *pt2 = (int *) b;
    char *dest = (char *) calloc (rows, sizeof (char));
    int *pt3 = (int *) dest;

    int col = max(strlen(a), strlen(b));

    for (int i = 0; i * sizeof (int) < col; i++)
        pt3[i] = pt1[i];
    for (int i = 0; i * sizeof (int) < col; i++)
        pt1[i] = pt2[i];
    for (int i = 0; i * sizeof (int) < col; i++)
        pt2[i] = pt3[i];

    free(dest);
}

char **DataPointer(char **data, const char *file) {

    assert(data);

    FILE *filename = fopen (file, "r");

    char string[1000];
    char **pointer = data;
    int i = 0;
    int c = 0;

    while ((c = getc (filename)) != EOF) {

        if (c != '\n') {
            string[i++] = c;
        }
        else {
            string[i] = '\0';
            *pointer++ = strdup (string);
            i = 0;
        }
    }
    return data;
}

char **DataPointerBuf(const char *file, int *NumOfWords) {

    FILE *filename = fopen(file, "r");
    int size = 2, c = 0, numofchar = 0, numofword = 0, sizedata = 2;

    char **data = (char **) calloc (sizedata, sizeof (char *));
    char **pointer = data;
    char *buf = (char *) calloc (size, sizeof (char));

    while ((c = getc (filename)) != EOF) {

        if (numofchar+1 == size) {
                size *= 2;
                buf = (char *)realloc (buf, size);
        }

        if (c != '\n') {
            buf[numofchar++] = c;
        }
        else {
            if (++numofword > sizedata) {
                sizedata *= 2;
                data = (char **) realloc (data, sizedata * sizeof(char*));
                if (data == NULL)
                    return NULL;
                pointer = data + numofword - 1;
            }
            buf[numofchar] = '\0';
            *pointer++ = strdup (buf);
            assert(pointer[-1]);
            numofchar = 0;
        }
    }
    free(buf);
    *NumOfWords = numofword;
    return data;
}

void SortStrPtr(char **data, size_t len) {

    int sorted = 1;
    do {
        sorted = 1;
        for (size_t i = 0; i < len - 1; i++) {
            if (strcmp(*(data + i), *(data + i + 1)) > 0) {
                sorted = 0;
                swapptr(*(data + i), *(data + i + 1));
            }
        }
    } while (!sorted);
}

void SortStr(char *data, size_t cols, size_t rows) {

    int sorted = 1;
    do {
        sorted = 1;
        for (size_t i = 0; i < cols - 1; i++) {
            if (strcmp(data + i * rows, data + (i + 1) * rows) > 0) {
                sorted = 0;
                swapwords(data + i * rows, data + (i + 1) * rows, rows);
            }
        }
    } while (!sorted);
}

char **fileread(struct Text *filedata, char *buffer) {

    assert(filedata->filename);

    char **data = (char **) calloc (filedata->NumOfStr, sizeof (char *));
    char *buf = (char *) calloc (filedata->filelen + 1, sizeof (char));

    fread(buf, sizeof (char), filedata->filelen, fopen("uncle.txt", "r"));

    *data = buf;
    int index = 1;

    for (size_t i = 0; i < filedata->filelen; i++) {
        if (buf[i] == '\n') {
            buf[i] = '\0';
            *(data + index++) = buf + i + 1;
            filedata->NumOfWords++;
        }
    }
    buffer = buf;
    return data;
}
