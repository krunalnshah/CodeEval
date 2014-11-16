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

#define RANGE_OF_NUMBERS    101

int CalculateDoubleSquare(int number)
{
    int numberOfWays = 0;
    int j = sqrt(number) + 1;
    int i = 0;
    int sum = 0;
    while (j >= i)
    {
        sum = j*j + i*i;
        if (sum == number)
        {
            numberOfWays++;
            j--;
            i++;
        }
        else if (sum > number)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return numberOfWays;
}

int CalculateDoubleSquare(string line)
{
    int number = atoi(line.c_str());

    return CalculateDoubleSquare(number);
}

int MAIN(int argc, TEXTCHAR* argv[])
{
    if (argc != 2)
    {
        return 0;
    }

    ifstream file(argv[1]);
    string line;

    if (file.is_open())
    {
        getline(file, line);
        int numberOfInputs = atoi(line.c_str());
        while (getline(file, line) && numberOfInputs--)
        {
            if (line.length() == 0)
            {
                continue;
            }
            cout << CalculateDoubleSquare(line) << endl;
        }
        file.close();
    }
    return 0;
}


