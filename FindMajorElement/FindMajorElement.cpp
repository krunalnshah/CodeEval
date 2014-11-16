// RightMostChar.cpp : Defines the entry point for the console application.
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

#define COUNTOF(X)  sizeof(X)/ sizeof(X[0])

int FindMajorElement(char* buffer)
{
    int number[100] = { 0 };
    char *temp = nullptr;
    int len = 0;

    if (!buffer)
    {
        return -1;
    }

    temp = strtok(buffer, ",");    
    while (temp != nullptr)
    {
        number[atoi(temp)]++;
        len++;
        temp = strtok(nullptr, ",");
    }

    for (int i = 0; i < COUNTOF(number); i++)
    {
        if (number[i] > len / 2)
        {
            return i;
        }
    }

    return -1;
}

int MAIN(int argc, TEXTCHAR* argv[])
{
    if (argc != 2)
    {
        return 0;
    }

    ifstream file(argv[1]);
    string line;
    char* buffer;
    int retVal;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.length() == 0)
            {
                continue;
            }
            buffer = (char*)malloc(line.length() + 1);
            if (!buffer)
            {
                break;
            }
            memset(buffer, 0, line.length() + 1);
            strcpy(buffer, line.c_str());
            retVal = FindMajorElement(buffer);
            if (retVal == -1)
            {
                cout << "None" << endl;
            }
            else
            {
                cout << retVal << endl;
            }
            free(buffer);
        }
        file.close();
    }
    return 0;
}

