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

#define NUMBER_OF_LETTERS 26

void IsPanagram(string line)
{
    bool letters[NUMBER_OF_LETTERS];
    bool panagram = true;

    for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    {
        letters[i] = false;
    }

    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] >= 'A' && line[i] <= 'Z')
        {
            letters[line[i] -'A'] = true;
        }
        else if (line[i] >= 'a' && line[i] <= 'z')
        {
            letters[line[i] - 'a'] = true;
        }
    }

    char character;
    for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    {
        if (!letters[i])
        {
            panagram = false;
            character = 'a' + i;
            cout << character;
        }
    }
    if (panagram)
    {
        cout << "NULL";
    }
    cout << endl;
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
        while (getline(file, line))
        {
            if (line.length() == 0)
            {
                continue;
            }
            IsPanagram(line);            
        }
        file.close();
    }
    return 0;
}


