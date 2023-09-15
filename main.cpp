#include <stdio.h>
#include "values.h"
#include "func.h"
#include "pointer.h"
#include <cstdlib>
#include "sort.h"

int main() {


    Text filedata = {0, NULL, 0, 0};
    SetStructText(&filedata, onegin_eng);

    Pointers ptrs = {0, {}};
    char *buffer = readbuf(&filedata);

    String data[filedata.NumOfStr];
    divstr(&filedata, &ptrs, data, buffer);

    SortStruct(data, filedata.NumOfStr);

    // Sort(data, &filedata);

    PrintData(data, filedata.NumOfStr);

    PrintDataFile(data, filedata.NumOfStr, onegin_output);

    Detor(&ptrs);

    return 0;
}
