#ifndef VALUES_ONEGIN
#define VALUES_ONEGIN

#include <stdio.h>

const char onegin_rus[] = "onegin_rus.txt";
const char onegin_eng[] = "onegin_eng.txt";
const char onegin_output[] = "onegin_out.txt";
const char read[] = "r";
const char write[] = "w";
const char append[] = "a";

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
    int col;
    char *ptrs[];
};

struct String {
    char *str;
    int len;
};

#endif
