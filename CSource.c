#include <stdio.h>
//#include "CppSource.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ReadIni.h"

int main(int argc, char* argv[])
{
    int ConstVec[] = { 0,1,2,3 };

    IniData iniData;

    ReadIni(&iniData);

    return 0;
}