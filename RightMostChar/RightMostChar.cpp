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

int RightMostInstance(string buffer, char character)
{
    int position = -1;
    int bufLen = buffer.length() - 2;
    
    for (int i = bufLen; i >= 0; i--)
    {
        if (buffer[i] == character)
        {
            position = i;
            break;
        }
    }

    return position;
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
            character = line[line.length()-1];
            line[line.length() - 2] = '\0';
            cout << RightMostInstance(line, character) << endl;
        }
        file.close();
    }
    return 0;
}

