// ReverseWords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "windows.h"
#include <string>
using namespace std;

bool ReverseAndPrintWord(char* word)
{
    char* start = word;
    char* end = word;

    if (word == nullptr)
    {
        return false;
    }

    while (*end)
    {
        end++;
    }
    end--;

    char tmp;
    while (end > start)
    {
        tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
   
    return true;
}

bool ReverseAndPrintLine(string line)
{
    char buf[1024] = { 0 };
    if (line.length() > 1023)
    {
        return false;
    }
    strcpy(buf, line.c_str());
    char* word = nullptr;

    word = strtok(buf, " ");
    ReverseAndPrintWord(word);
    cout << word;
    while (word != nullptr)
    {
        word = strtok(nullptr, " ");
        if (word == nullptr)
        {
            break;
        }
        cout << " ";
        if (!ReverseAndPrintWord(word))
        {
            return false;
        }
        cout << word;
    }

    return true;
}

bool IsEmptyLine(string line)
{
    for (unsigned int i = 0; i < line.length(); i++)
    {
        if (line[i] != ' ' && line[i] != '\r' && line[i] != '\n')
        {
            return false;
        }
    }
    return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
    if (argc != 2)
    {
        return -1;
    }
    ifstream inputFile(argv[1]);

    string line;
    while (getline(inputFile, line))
    {
        if (!IsEmptyLine(line))
        {
            if (!ReverseAndPrintLine(line))
            {
                cout << "Invalid line" << endl;
                break;
            }
        }
    }

    return 0;
}

