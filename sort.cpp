#include <stdio.h>
#include "sort.h"
#include "func.h"
#include "pointer.h"
#include <assert.h>
#include "values.h"
#include <ctype.h>
#include <string.h>

void PrintDataSort(int *data, int left_c, int right_c, int left, int right, int mid) {

    for (int i = left_c; i < right_c; i++) {

        if (i == left)
            fprintf(stderr, "<");

        if (i == mid)
            fprintf(stderr, "[");

        fprintf(stderr, "%d", data[i]);

        if (i == mid)
            fprintf(stderr, "]");

        if (i == right)
            fprintf(stderr, ">");

        fprintf(stderr, " ");
    }
    fprintf(stderr, "\n\n");
}

void SortBubble(int *data, size_t len) {

    assert(data);

    int sorted = 0;
    for (size_t n = 0; n < len; n++) {

        sorted = 1;
        for (size_t i = 0; i < len - n - 1; i++) {

            if (data[i] > data[i + 1]) {
                swap(data[i], data[i + 1]);
                sorted = 0;
            }
        }

        if (sorted)
            break;
    }
}

void SortChoice(int *data, size_t len) {

    assert(data);

    for (size_t i = 0; i < len; i++) {
        swap(data[FindMinIndex(data + i, len - i) + i], data[i]);
    }
}

int FindMinIndex(int *data, int len) {

    size_t index = 0;
    for (size_t i = 0; i < len; i++) {
        if (data[index] > data[i])
            index = i;
    }
    return index;
}

int CompareSructRev(const String *st1, const String *st2) {

    assert(st1);
    assert(st2);
    assert(st1->str);
    assert(st2->str);

    char *a = st1->str;
    char *b = st2->str;
    int len_a = st1->len, len_b = st2->len;

    a += len_a - 1;
    b += len_b - 1;

    if (len_a == 0) {
        if (len_b == 0)
            return 0;
        else
            return -1;
    }

    if (len_b == 0) {
        if (len_a == 0)
            return 0;
        else
            return 1;
    }

    while (a > st1->str || b > st2->str) {

        if (!isalpha(*a)) {
            a--;
            continue;
        }
        if (!isalpha(*b)) {
            b--;
            continue;
        }

        if (a == st1->str) {
            if (b == st2->str)
                return 0;
            else
                return -1;
        }
        if (b == st2->str) {
            if (a == st1->str)
                return 0;
            else
                return 1;
        }

        if (*a != *b)
            return strcmp(a--, b--);
        a--;
        b--;

    }
    return 0;
}

int partition(String *data, size_t left, size_t right) {

    assert(data);

    right--;

    int mid = randnum(left, right);

    String board = data[mid];

    while (left < right) {
        assert(data[left].str);
        while (CompareSructRev(&data[left], &board) < 0) {
            left++;
        }

        while (CompareSructRev(&data[right], &board) > 0) {
            right--;
        }

        if (right != left) {
            if (CompareSructRev(&data[left], &data[right]) == 0) {
                if (CompareSructRev(&data[left], &board) < 0)
                    left++;
                else
                    right--;
            }
            else {
            String temp = {};
            temp = data[left];
            data[left] = data[right];
            data[right] = temp;
            }
        }

    }
    mid = min(left, right);

    return mid;
}

int randnum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int compint(int a, int b) {
    return a = b;
}

int compchar(char a, char b) {
    return a == b;
}

int CompareStruct(const void *a, const void *b) {

    assert(a);
    assert(b);

    const String *st1 = (String *) a;
    const String *st2 = (String *) b;

    Compare words = {st1->str, st2->str, st1->len, st2->len};

    return CompStrRev(&words);
}

int CompStrRev(const struct Compare *words) {

    assert(words);
    assert(words->a);
    assert(words->b);

    char *a = words->a;
    char *b = words->b;
    int len_a = words->len_a, len_b = words->len_b;

    a += len_a - 1;
    b += len_b - 1;

    if (len_a == 0) {
        if (len_b == 0)
            return 0;
        else
            return -1;
    }

    if (len_b == 0) {
        if (len_a == 0)
            return 0;
        else
            return 1;
    }

    while (a > words->a || b > words->b) {

        if (!isalpha(*a)) {
            a--;
            continue;
        }
        if (!isalpha(*b)) {
            b--;
            continue;
        }

        if (a == words->a) {
            if (b == words->b)
                return 0;
            else
                return -1;
        }
        if (b == words->b) {
            if (a == words->a)
                return 0;
            else
                return 1;
        }

        if (*a != *b)
            return strcmp(a--, b--);
        a--;
        b--;

    }
    return 0;
}

/**
 * Sorts strings from the end
 *
 * @param data Array of structs with information about lines
 * @param filedata Struct with filedata
 */
void Sort(String *data, struct Text *filedata) {

    qsort(data, filedata->NumOfStr - 1, sizeof (String), CompareStruct);
}

int CompString(const String *a, const String *b) {

    assert(a);
    assert(b);

    return strcmp(a->str, b->str);
}

int compsrt(const void *a, const void *b) {

    assert(a);
    assert(b);

    return strcmp((char *) a, (char *) b);
}

void Myqsort(String *data, size_t left, size_t right) {

    assert(data);

    int mid = partition(data, left, right);

    if (right - left > 1) {
        if (mid - left > 1)
            Myqsort(data, left, mid);
        if (right - mid > 1)
            Myqsort(data, mid + 1, right);
    }
    else if (left + 1 == right)
        if (CompareSructRev(&data[left], &data[right]) > 0) {
            String temp = {};
            temp = data[left];
            data[left] = data[right];
            data[right] = temp;
        }
}
