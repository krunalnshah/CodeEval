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

bool IsRotation(char* originalString, char* str)
{
    string appendedStr(str);
    appendedStr.append(str);

    size_t position = appendedStr.find(originalString);
    if (position != string::npos)
    {
        return true;
    }
    return false;
}

bool IsRotation(string line)
{    
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    if (line.length() > sizeof(buffer))
    {
        return false;
    }

    strcpy(buffer, line.c_str());

    char* originalString = strtok(buffer, ",");
    char* str = strtok(nullptr, ",");

    if (IsRotation(originalString, str))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
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
            if (!IsRotation(line))
            {
                break;
            }
        }
        file.close();
    }
    return 0;
}

