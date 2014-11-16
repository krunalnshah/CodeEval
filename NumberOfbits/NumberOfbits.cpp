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

#define NUMBER_OF_BITS  32

int CalculateNumberOfBits(string line)
{
    int number = atoi(line.c_str());
    int numberOfBits = 0;

    int i = 0;
    while (i < NUMBER_OF_BITS)
    {
        if (number & 1)
        {
            numberOfBits++;
        }
        number = number >> 1;
        i++;
    }

    return numberOfBits;
}

int MAIN(int argc, TEXTCHAR* argv[])
{
    if (argc != 2)
    {
        return 0;
    }

    ifstream file(argv[1]);
    string line;
    char character;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.length() == 0)
            {
                continue;
            }
            cout << CalculateNumberOfBits(line) << endl;
        }
        file.close();
    }
    return 0;
}

