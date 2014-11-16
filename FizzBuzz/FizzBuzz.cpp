// FizzBuzz.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <stdio.h>
using namespace std;

#define FIZZ 'F'
#define BUZZ 'B'
#define FIZZBUZZ 'FB'

#ifdef  WINDOWS
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

void PrintSequence(int fizz, int buzz, int max)
{
    for (int i = 1; i <= max; i++)
    {
        if (i%fizz == 0 && i%buzz == 0)
        {
            PRINT(TEXT("%s"), TEXT("FB "));
        }
        else if (i%fizz == 0)
        {
            PRINT(TEXT("%s"), TEXT("F "));
        }
        else if (i%buzz == 0)
        {
            PRINT(TEXT("%s"), TEXT("B "));
        }
        else
        {
            PRINT(TEXT("%d "), i);
        }

    }

    cout << endl;
    return;
}

int MAIN(int argc, TEXTCHAR* argv[])
{
    int fizz, buzz, max;

    if (argc != 2)
    {
        return 0;
    }

    ifstream file(argv[1]);
    string line;
    char buf[256];
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.length() > sizeof(buf) - 1)
            {
                break;
            }
            memset(buf, 0, sizeof(buf));
            strcpy(buf, line.c_str());
            sscanf(buf, "%d %d %d", &fizz, &buzz, &max);
            PrintSequence(fizz, buzz, max);
        }
        file.close();
    }    
	return 0;
}

