#ifndef POINTER_FUNC
#define POINTER_FUNC

#include <stdio.h>

char **DataPointer(char **data, const char *file);
char **DataPointerBuf(const char *file, int *NumOfWords);
void swapptr(char *a, char *b);
void swapwords(char *a, char *b, const int rows);
void SortStrPtr(char **data, size_t len);
void SortStr(char *data, size_t cols, size_t rows);
struct String **fileread(struct Text *filedata, struct Pointers *dataptr);
void Detor(struct Pointers *data);

#endif
