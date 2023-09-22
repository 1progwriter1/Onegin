#ifndef POINTER_FUNC
#define POINTER_FUNC

#include <stdio.h>
#include "values.h"

void swapptr(char *a, char *b);
void SortStruct(String *data, size_t len);
void divstr(struct Text *filedata, struct Pointers *dataptr, String *data, char *buf);
void Detor(struct Pointers *data);
char *readbuf(struct Text *filedata);
String *OpenFile(struct Text *filedata, struct Pointers *ptrs);

#endif
