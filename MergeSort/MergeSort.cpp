// MergeSort.cpp : Defines the entry point for the console application.
//

#define WINDOWS

#ifdef  WINDOWS
#include "stdafx.h"

#define PRINT _tprintf
#define TEXT _T
#define MAIN _tmain
#define TEXTCHAR _TCHAR
#else

#define PRINT printf
#define TEXT 
#define MAIN main
#define TEXTCHAR char
#endif

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

unsigned int Merge(int * a, int* temp, int start, int mid, int end)
{
    int finalArrayposition = start;
    int leftArrayPosition = start;
    int rightArrayPosition = mid + 1;
    unsigned int inversion = 0;
    while (leftArrayPosition <= mid && rightArrayPosition <= end)
    {
        if (a[leftArrayPosition] > a[rightArrayPosition])
        {
            temp[finalArrayposition] = a[rightArrayPosition];
            rightArrayPosition++;
            finalArrayposition++;
            inversion += mid - leftArrayPosition + 1;
        }
        else
        {
            temp[finalArrayposition] = a[leftArrayPosition];
            leftArrayPosition++;
            finalArrayposition++;

        }
    }

    for (int i = leftArrayPosition; i <= mid; i++)
    {
        temp[finalArrayposition] = a[leftArrayPosition];
        leftArrayPosition++;
        finalArrayposition++;
    }

    for (int i = rightArrayPosition; i <= end; i++)
    {
        temp[finalArrayposition] = a[rightArrayPosition];
        rightArrayPosition++;
        finalArrayposition++;
    }


    for (int i = start; i <= end; i++)
    {
        a[i] = temp[i];
    }

    return inversion;
}

unsigned int MergeSort(int* a, int* temp, int start, int end)
{
    unsigned int rightInversion = 0;
    unsigned int leftInversion = 0;
    unsigned int totalInversion = 0;

    if (end > start)
    {
        int mid = (start + end) / 2;
        leftInversion = MergeSort(a, temp, start, mid);
        rightInversion = MergeSort(a, temp, (mid + 1), end);
        totalInversion = Merge(a, temp, start, mid, end);
    }
    return leftInversion + rightInversion + totalInversion;
}

int _tmain(int argc, _TCHAR* argv[])
{
    int b[] = { 8, 2, 1, 3, 4, 5 };

    if (argc != 2)
    {
        return 0;
    }
    int* a = (int*)malloc(100000 * sizeof(int));
    int* temp = (int*)malloc(100000 * sizeof(int));
    ifstream file(argv[1]);
    string line;
    int i = 0;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.length() == 0)
            {
                continue;
            }
            a[i] = atoi(line.c_str());
            i++;
        }
        file.close();
    }

    unsigned int inversion = MergeSort(a, temp, 0, i - 1);
    _tprintf(_T("Inversion is %u"), inversion);
    return 0;
}


