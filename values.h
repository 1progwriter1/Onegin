#include <stdio.h>

struct Text {
        long long int filelen;
        FILE *filename;
        long long int NumOfStr;
        int NumOfWords;
    };

struct Compare {
    char *a;
    char *b;
    int lena;
    int lenb;
    int col;
};
