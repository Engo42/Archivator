#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "pack.h"
#include "unpack.h"


int main(int argc, char* argv[])
{
    if (argv[1][0] == 'p')
        pack(argv[2]);
    if (argv[1][0] == 'u')
        unpack(argv[2]);

    return 0;
}