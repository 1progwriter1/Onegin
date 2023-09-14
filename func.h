#ifndef FUNC_ONEGIN
#define FUNC_ONEGIN

#include <stdio.h>

void swap(int &a, int &b);
int max(int a, int b);
long long int filelen(const char *filename);
FILE *fileopen(const char *filename);
int min(int a, int b);
long long int NumOfStr(const char *str, size_t len);
void SetStructText(struct Text *data, const char *filename);
void PrintData(struct String **data, long long int NumOfStr);

#endif
