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

int IsSelfDescribingNumber(string line)
{
    if (line.length() <= 0)
    {
        return -1;
    }

    int digit[10] = { 0 };

    int remainder = 0;
    int number = atoi(line.c_str());
    if (number <= 0)
    {
        return -1;
    }

    while (number > 0)
    {
        remainder = number % 10;
        digit[remainder]++;
        number = number / 10;
    }

    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] - '0' != digit[i])
        {
            return false;
        }
    }

    return true;
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
            cout << IsSelfDescribingNumber(line) << endl;
        }        
        file.close();
    }
    return 0;
}


