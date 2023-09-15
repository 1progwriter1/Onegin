#include <stdio.h>
#include "values.h"
#include "func.h"
#include "pointer.h"
#include <cstdlib>
#include "sort.h"

int main(const int argc, const char *argv[]) {

    Args mainargs = {0, 0};
    GetArgs(argc, argv, &mainargs);

    Text filedata = {0, NULL, 0, 0};
    SetStructText(&filedata, onegin_big);

    Pointers ptrs = {NULL, NULL};
    char *buffer = readbuf(&filedata);

    String *data = (String *) calloc (filedata.NumOfStr, sizeof (String));
    divstr(&filedata, &ptrs, data, buffer);

    if (mainargs.file == 0) {

        if (mainargs.reverse == 0)
            SortStruct(data, filedata.NumOfStr);
        else
            Sort(data, &filedata);

        PrintData(data, filedata.NumOfStr);
    }
    else {
        cleanfile(onegin_output);
        SortStruct(data, filedata.NumOfStr);
        PrintDataFile(data, filedata.NumOfStr, onegin_output);
        Sort(data, &filedata);
        PrintDataFile(data, filedata.NumOfStr, onegin_output);
        fprintf(fileopen(onegin_big, APPEND), "%s", buffer);
    }

    Detor(&ptrs);

    return 0;
}
