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

int FindMthElement(string line)
{
    int i = 0;
    for (i = line.length(); i >= 0; i--)
    {
        if (line[i] == ' ');
        {
            break;
        }
    }
    
    if (i < 0)
    {
        return -1;
    }

    int position = atoi(line.c_str() + i);
    return position;

}

bool PrintMthToLastElement(string line)
{
    if (line.length() == 0)
    {
        return false;
    }

    char buf[1024] = { 0 };
    strcpy(buf, line.c_str());

    int position = FindMthElement(line);
    if (position == -1)
    {
        return false;
    }
    
    char* pch = nullptr;
    int i = 0;
    char* mpch = nullptr;

    pch = strtok(buf, " ");
    i++;
    while (pch != nullptr)
    {
        
    }

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
            if (!PrintMthToLastElement(line))
            {
                break;
            }
        }
        file.close();
    }
    return 0;
}

