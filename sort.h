#ifndef SORT_FUNC
#define SORT_FUNC

#include "values.h"

void SortBubble(int *data, size_t len);
void SortChoice(int *data, size_t len);
int FindMinIndex(int *data, int len);
void SortPart(int *data, size_t left, size_t right);
int partition(int *data, size_t left, size_t right);
int randnum(int min, int max);
int compint(int a, int b);
int compchar(char a, char b);
int CompStrRev(const struct Compare *words);
void PrintDataSort(int *data, int left_c, int right_c, int left, int right, int mid);
int compare(const void *a, const void *b);
void Sort(String *data, struct Text *filedata);

#endif
