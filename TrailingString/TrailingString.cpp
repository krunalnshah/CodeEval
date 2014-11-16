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

int Find(char* mainString, char* stringToSearch)
{
    if (!mainString || !stringToSearch)
    {
        return -1;
    }

    char* mainStringIterator = mainString;
    char* stringToSearchIterator = stringToSearch;

    while (*mainStringIterator)
    {
        mainStringIterator++;
    }

    while (*stringToSearchIterator)
    {
        stringToSearchIterator++;
    }


    while (mainStringIterator >= mainString && stringToSearchIterator >= stringToSearch)
    {
        if (*mainStringIterator != *stringToSearchIterator)
        {
            return 0;
        }
        mainStringIterator--;
        stringToSearchIterator--;
    }
    
    return 1;
}

int TrailingString(char* buf)
{
    char* mainString = nullptr;
    char* stringToSearch = nullptr;
    if (!buf)
    {
        return -1;
    }

    mainString = strtok(buf, ",");
    if (!mainString)
    {
        return 0;
    }

    stringToSearch = strtok(nullptr, ",");
    if (!stringToSearch)
    {
        return 0;
    }

    return Find(mainString, stringToSearch);
}

int MAIN(int argc, TEXTCHAR* argv[])
{
    if (argc != 2)
    {
        return 0;
    }

    ifstream file(argv[1]);
    string line;
    char buf[4096];
    memset(buf, 0, sizeof(buf));
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.length() == 0)
            {
                continue;
            }
            strcpy(buf, line.c_str());
            cout << TrailingString(buf) << endl;
        }
        file.close();
    }
    return 0;
}

