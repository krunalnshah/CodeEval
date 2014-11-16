// IncreasingOrder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



void PrintIncreasing(char* array, int start, int end, int index, int length)
{
    if (!array)
    {
        return;
    }

    if (length == 0)
    {
        return;
    }

    if (index == length)
    {
        array[index] = '\0';
        printf(array);
        return;
    }

    for (int i = start; i < (end - length + index + 1);)
    {
        array[index] = i;
        i++;
        PrintIncreasing(array, i, end, index + 1, length);
    }


}
int _tmain(int argc, _TCHAR* argv[])
{

    char array[4];
    PrintIncreasing(array, 1, 6, 0, 3);

    return 0;
}


