#ifndef POINTER_FUNC
#define POINTER_FUNC

#include <stdio.h>
#include "values.h"

char **DataPointer(char **data, const char *file);
char **DataPointerBuf(const char *file, int *NumOfWords);
void swapptr(char *a, char *b);
void swapwords(char *a, char *b, const int rows);
void SortStruct(String *data, size_t len);
void SortStr(char *data, size_t cols, size_t rows);
void divstr(struct Text *filedata, struct Pointers *dataptr, String *data, char *buf);
void Detor(struct Pointers *data);
char *readbuf(struct Text *filedata);

#endif
