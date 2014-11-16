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

bool  PrintIntersection(int* set1, int len1, int* set2, int len2)
{
    if (!set1 || !set2 || len1 == 0 || len2 == 0)
    {
        return false;
    }

    int i = 0;
    int j = 0;
    bool firstElement = false;
    while (i < len1 && j < len2)
    {
        if (set1[i] > set2[j])
        {
            j++;
        }
        else if (set1[i] < set2[j])
        {
            i++;
        }
        else
        {
            if (!firstElement)
            {
                cout << set1[i];
                firstElement = true;
            }
            else
            {
                cout << "," << set1[i];
            }
            i++;
            j++;
    
        }
    }


    return true;
}

bool ExtractSet(char* buffer, int** set, int* len)
{
    if (!buffer || !set || !len)
    {
        return false;
    }

    int bufLen = strlen(buffer);
    *set = (int*)malloc(bufLen * sizeof(int));
    int *array = *set;
    int setLength = 0;

    char *tmp = nullptr;
    tmp = strtok(buffer, ",");    
    while (tmp != nullptr)
    {
        array[setLength++] = atoi(tmp);        
        tmp = strtok(nullptr, ",");        
    }
    *len = setLength;

    return true;
}

bool ExtractSet(char* buffer, int **set1, int* len1, int** set2, int* len2)
{
    if (!buffer || !set1 || !len1 || !set2 || !len2)
    {
        return false;
    }

    char* charSet1 = nullptr;
    char* charSet2 = nullptr;

    charSet1 = strtok(buffer, ";");
    if (charSet1 == nullptr)
    {
        return false;
    }

    charSet2 = strtok(nullptr, ";");
    if (charSet2 == nullptr)
    {
        return false;
    }

    if (!ExtractSet(charSet1, set1, len1))
    {
        return false;
    }

    if (!ExtractSet(charSet2, set2, len2))
    {
        return false;
    }

    return true;
}


bool PrintIntersection(char* buffer)
{
    if (!buffer)
    {
        return false;
    }
    int *set1 = nullptr;
    int *set2 = nullptr;
    int len1 = 0;
    int len2 = 0;

    if (!ExtractSet(buffer, &set1, &len1, &set2, &len2))
    {
        return false;
    }

    if (!PrintIntersection(set1, len1, set2, len2))
    {
        return false;
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
    char buffer[1024];
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.length() == 0)
            {
                continue;
            }
            memset(buffer, 0, sizeof(buffer));
            strcpy(buffer, line.c_str());
            if (!PrintIntersection(buffer))
            {
                break;
            }
            cout << endl;
        }
        file.close();
    }
    return 0;
}

