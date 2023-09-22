#ifndef VALUES_ONEGIN
#define VALUES_ONEGIN

#include <stdio.h>

const char Onegin_rus[] = "onegin_rus.txt";
const char Onegin_eng[] = "onegin_eng.txt";
const char Onegin_output[] = "onegin_out.txt";
const char Onegin_big[] = "onegin.txt";
const char READ[] = "r";
const char WRITE[] = "w";
const char APPEND[] = "a";

struct Text {
        long long int filelen;
        FILE *filename;
        long long int NumOfWords;
        long long int NumOfStr;
};

struct Compare {
    char *a;
    char *b;
    int len_a;
    int len_b;
};

struct Pointers {
    char *buffer;
    char *data;
};

struct String {
    char *str;
    int len;
};

struct Args {
    int file;
    int numfile;
};

enum Result {
    SUCCESS,
    FILENAME_ERROR,
    FILEOPEN_ERROR
};

#endif
