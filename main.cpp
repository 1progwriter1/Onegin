#include <stdio.h>
#include "values.h"
#include "func.h"
#include "pointer.h"
#include <cstdlib>
#include "sort.h"

/**
 * Sorts the poem Eugene Onegin
 *
 * @param argv Output file
 *
 * @return Straight sort, Reverse sort, Original text
 *
 * @note The result outputs to stdout or in the file transferred to the main.
 */

int main(const int argc, const char *argv[]) {

    Args mainargs = {0, 0};
    if (!GetArgs(argc, argv, &mainargs))
        return FILENAME_ERROR;

    Text filedata = {0, NULL, 0, 0};
    Pointers ptrs = {NULL, NULL};

    String *data = OpenFile(&filedata, &ptrs);

    FILE *fn = stdout;
    if (mainargs.file == 1) {
        fn = fileopen(argv[mainargs.numfile], WRITE);
        if (!fn)
            return FILEOPEN_ERROR;
    }

    SortStruct(data, filedata.NumOfStr);
    PrintDataFile(data, filedata.NumOfStr, fn);
    Sort(data, &filedata);
    PrintDataFile(data, filedata.NumOfStr, fn);
    PrintfOrigin(&filedata, fn);
    fileclose(fn);

    Detor(&ptrs);

    return SUCCESS;
}
