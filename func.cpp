#include <stdio.h>
#include "func.h"
#include <assert.h>
#include <sys/stat.h>
#include <errno.h>
#include "values.h"
#include <string.h>
#include "pointer.h"

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

    assert(str);

    int c = 0, col = 1;
    for (size_t i = 0; i < len; i++) {
        if (str[i] == '\n')
            col++;
    }
    return col;
}
/**
 * Fills the struct Text with file data
 *
 * @param data Struct with file data
 * @param filename The file about which information is recorded
 */
void SetStructText(struct Text *data, const char *filename) {

    assert(data);

    data->filelen = filelen(filename);
    data->filename = fileopen(filename, READ);
    data->NumOfWords = 0;
    data->NumOfStr = 0;

}
/**
 * Prints lines from array of structs to the file
 *
 * @param data Array of structs
 * @param NumOfStr Number of lines
 * @param fn Output file
 */
void PrintDataFile(String *data, long long int NumOfStr, FILE *fn) {

    assert(data);
    assert(fn);

    for (size_t i = 0; i < NumOfStr - 1; i++) {
        if (data[i].len == 0)
            continue;
        fprintf(fn, "%s\n", data[i].str);
    }
    fprintf(fn, "\n");
}
/**
 * Gets the Args from main() function
 *
 * @param argc Number of arguments
 * @param argv Arguments
 * @param maindata Struct of resulting information
 * @return 1 or 0
 *
 * @note Outputs 1 if the arguments are correct. 0 otherwise
 */
int GetArgs(int argc, const char *argv[], struct Args *maindata) {

    maindata->file = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--file") == 0) {
            if (++i == argc) {
                printf("File name expected\n");
                return 0;
            }
            else {
                maindata->file = 1;
                maindata->numfile = i;
            }
        }

        else printf("Invalid argument %s\n", argv[i]);
    }
    return 1;
}

void cleanfile(const char *filename) {
    FILE *fn = fileopen(filename, WRITE);
}

void fileclose(FILE *fn) {

    assert(fn);

    if (fn != stdout)
        if (fclose(fn) != 0)
            fprintf(stderr, "File not closed\n");
}

/**
 * Prints original text from the file to the output file
 *
 * @param filedata Struct with info about file
 * @param fn Output file
 */
void PrintfOrigin(struct Text *filedata, FILE *fn) {

    assert(filedata);
    assert(fn);

    SetStructText(filedata, Onegin_big);

    char *buffer = readbuf(filedata);

    fprintf(fn, "%s", buffer);

    free(buffer);

    fileclose(filedata->filename);

}
