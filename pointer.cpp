#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "func.h"
#include "values.h"
#include "sort.h"

void swapptr(char *a, char *b) {

    char *temp = a;
    a = b;
    b = temp;
}

void swapstruct(String *st1, String *st2) {

        assert(st1);
        assert(st2);

        String *temp = st1;
        st1 = st2;
        st2 = temp;
}

/**
 * Sorts lines
 *
 * @param data Array of structs with information about lines
 * @param len Length of array
 */
void SortStruct(String *data, size_t len) {

    assert(data);

    int sorted = 1;
    do {
        sorted = 1;
        for (size_t i = 0; i < len - 2; i++) {
            if (strcmp(data[i].str, data[i + 1].str) > 0) {
                sorted = 0;
                String temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
            }
        }
    } while (!sorted);
}

/**
 * Reads text from file
 *
 * @param filedata Struct with file data
 *
 * @return Pointer to the read text
 */
char *readbuf(struct Text *filedata) {

    assert(filedata);
    assert(filedata->filename);

    char *buf = (char *) calloc (filedata->filelen + 1, sizeof (char));
    fread(buf, sizeof (char), filedata->filelen, filedata->filename);

    filedata->NumOfStr = NumOfStr(buf, filedata->filelen);

    return buf;
}

/**
 * Splits text into strings and writes information about them into an array of structures
 *
 * @param filedata Struct with filedata
 * @param dataptr Struct with memory addresses
 * @param data Array of structs with information about lines
 * @param buf Pointer to the text
 *
 * @return Pointer to the array if structs with information about lines
 */
String *divstr(struct Text *filedata, struct Pointers *dataptr, String *data, char *buf) {

    assert(filedata);
    assert(dataptr);
    assert(data);
    assert(buf);

    int length = 0;
    char *nextstr = buf;

    int index = 0;

    for (size_t i = 0; i < filedata->filelen; i++) {

        if (*(buf + i) == '\n') {
            *(buf + i) = '\0';
            data[index].len = length;
            data[index++].str = nextstr;
            nextstr = buf + i + 1;
            length = 0;
        }
        else {
            length++;
        }
    }
    dataptr->buffer = buf;
    dataptr->data = (char *) data;

    fileclose(filedata->filename);

    return data;

}
/**
 * Frees up memory specified in struct Pointers
 *
 * @param data Struct with memory addresses
 */
void Detor(struct Pointers *data) {

    assert(data);

    free(data->buffer);
    free(data->data);
}

/**
 * Writes information about strings from file to an array of structures
 *
 * @param filedata Struct with ifromstion about file
 * @param ptrs Struct with memory addresses
 *
 * @return Pointer to an array of structures
 */
String *OpenFile(struct Text *filedata, struct Pointers *ptrs) {

    assert(filedata);
    assert(ptrs);

    SetStructText(filedata, Onegin_big);
    char *buffer = readbuf(filedata);

    String *data = (String *) calloc (filedata->NumOfStr, sizeof (String));

    return divstr(filedata, ptrs, data, buffer);

}
