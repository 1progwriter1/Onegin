#ifndef SORT_FUNC
#define SORT_FUNC

#include "values.h"

void SortBubble(int *data, size_t len);
void SortChoice(int *data, size_t len);
int FindMinIndex(int *data, int len);
int partition(String *data, size_t left, size_t right);
int randnum(int min, int max);
int compint(int a, int b);
int compchar(char a, char b);
int CompStrRev(const struct Compare *words);
void PrintDataSort(int *data, int left_c, int right_c, int left, int right, int mid);
int CompareSructRev(const String *a, const String *b);
int CompareStruct(const void *a, const void *b);
void Sort(String *data, struct Text *filedata);
int CompString(const String *a, const String *b);
void Myqsort(String *data, size_t left, size_t right);

#endif
