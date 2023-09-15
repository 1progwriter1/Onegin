#include <stdio.h>
#include "sort.h"
#include "func.h"
#include "pointer.h"
#include <assert.h>
#include "values.h"
#include <ctype.h>
#include <string.h>

void OneginSortRev(const char *filename) {
}

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

void SortPart(int *data, size_t left, size_t right) {

    assert(data);

    int mid = partition(data, left, right);
    if (right - left > 1) {
        if (mid - left > 1)
            SortPart(data, left, mid);
        if (right - mid > 1)
            SortPart(data, mid + 1, right);
    }
    else if (left + 1 == right)
        if (data[left] > data[right])
            swap(data[left], data[right]);

}

int partition(int *data, size_t left, size_t right) {

    assert(data);

    int mid = (left + right) / 2;

    int left_c = left;
    int right_c = right;

    right--;

    int board = data[mid];

    fprintf(stderr, "!!!!!!%d\n\nBase: ", board);

    for (int i = left; i <= right; i++)
        fprintf(stderr, "%d ", data[i]);
    fprintf(stderr, "\n\n");

    int col = 0, num = 1;

    while (left < right && col++ < 100) {

        /* for (int i = left_c; i <= right_c; i++)
            printf("%d ", data[i]);
        printf("\n"); */

        fprintf(stderr, "Searching for Left bad element: ");

        while (data[left] < board) {
            left++;
            fprintf(stderr, "%lu... ", left);
        }

        fprintf(stderr, "FOUND [%lu], elem = %d\n", left, data[left]);

        fprintf(stderr, "Searching for Right bad element: ");

        while (data[right] >= board) {
            right--;
            fprintf(stderr, "%lu... ", right);
        }

        fprintf(stderr, "FOUND [%lu], elem = %d\n\n", right, data[right]);

        PrintDataSort(data, left_c, right_c, left, right, -1);

        /* printf("%d\n", data[0]); */
        if (right != left) {
            fprintf(stderr, "Swapping [%lu] = %d and [%lu] = %d\n\n", left, data[left], right, data[right]);

            swap(data[left], data[right]);
        }

    }
    mid = min(left, right);

    PrintDataSort(data, left_c, right_c, -1, -1, mid);

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

        if (!isalpha(*a))
            a--;
        if (!isalpha(*b))
            b--;

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

int compare(const void *a, const void *b) {

    assert(a);
    assert(b);

    const String *s1 = (String *) a;
    const String *s2 = (String *) b;

    Compare words = {s1->str, s2->str, s1->len, s2->len};

    return CompStrRev(&words);

}

void Sort(String *data, struct Text *filedata) {

    qsort(data, filedata->NumOfStr - 1, sizeof (String), compare);
}
