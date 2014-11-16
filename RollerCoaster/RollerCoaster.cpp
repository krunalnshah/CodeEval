// RollerCoaster.cpp : Defines the entry point for the console application.
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

char LowerCase(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
    {
        letter = letter - 'A' + 'a';
    }
    return letter;
}

char UpperCase(char letter)
{
    if (letter >= 'a' && letter <= 'z')
    {
        letter = letter - 'a' + 'A';
    }
    return letter;
}

bool IsLetter(char letter)
{
    if ( (letter >= 'A' && letter <= 'Z')
        || (letter >= 'a' && letter <= 'z'))
    {
        return true;
    }
    return false;
}

bool RollerCoasterLine(string line)
{
    int j = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (IsLetter(line[i]))
        {
            if (j % 2 == 0)
            {
                line[i] = UpperCase(line[i]);
            }
            else
            {
                line[i] == LowerCase(line[i]);
            }
            j++;
        }
    }
    cout << line << endl;
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
    if (file.is_open())
    {
        while (getline(file, line))
        {
            RollerCoasterLine(line);
        }
        file.close();
    }
	return 0;
}

