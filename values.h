#include <stdio.h>

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
