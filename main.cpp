#include <stdio.h>
#include "values.h"
#include "func.h"
#include "pointer.h"

int main() {

    const char onegin_rus[] = "onegin_rus.txt";
    const char onegin_eng[] = "onegin_eng.txt";

    Text filedata = {0, NULL, 0, 0};
    SetStructText(&filedata, onegin_rus);

    Pointers ptrs = {0, {}};
    struct String **data = fileread(&filedata, &ptrs);

    // PrintData(data, filedata.NumOfStr);

    Detor(&ptrs);

    return 0;
}
