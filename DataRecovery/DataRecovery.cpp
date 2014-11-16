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

class Word
{
public:
    Word()
    {
        pch = nullptr;
        position = -1;
    }
    char* pch;
    int position;
};

bool ExtractWords(char* buffer, Word* words, int count, int* length)
{
    if (!buffer || !length || !words || count == 0)
    {
        return false;
    }

    char* wordSequence = nullptr;
    char* numberSequence = nullptr;

    wordSequence = strtok(buffer, ";");
    if (!wordSequence)
    {
        return false;
    }

    numberSequence = strtok(nullptr, ";");
    if (!numberSequence)
    {
        return false;
    }

    int position[64] = { 0 };

    char* numberTemp = nullptr;
    numberTemp = strtok(numberSequence, " ");
    int i = 0;
    while (numberTemp != nullptr)
    {
        position[i] = atoi(numberTemp);
        position[i]--; // make it 0 based
        if (numberTemp < 0)
        {
            return false;
        }
        i++;
        numberTemp = strtok(nullptr, " ");
    }

    *length = i + 1;

    int number[64] = { 0 };
    for (int k = 0; k < i; k++)
    {
        number[position[k]] = 1;
    }

    for (int k = 0; k < *length; k++)
    {
        if (number[k] == 0)
        {
            position[i] = k;
        }
    }

    char* wordTemp = nullptr;

    int j = 0;
    wordTemp = strtok(wordSequence, " ");
    while (wordTemp != nullptr)
    {
        words[position[j]].pch = wordTemp;
        j++;
        wordTemp = strtok(nullptr, " ");
    }
    
    return true;
}

bool PrintWords(Word* words, int length)
{

    if (!words)
    {
        return false;
    }
    bool firstWordPrinted = false;

    for (int i = 0; i < length; i++)
    {
        if (!firstWordPrinted)
        {
            firstWordPrinted = true;
        }
        else
        {
            cout << " ";
        }
        cout << words[i].pch;
    }
    cout << endl;

    return true;
}

bool DataRecovery(char* buffer)
{
    Word words[64];
    int length = 0;

    if (!ExtractWords(buffer, words, sizeof(words)/ sizeof(Word), &length))
    {
        return false;
    }

    if (!PrintWords(words, length))
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
    char buffer[4096];

    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.length() == 0)
            {
                continue;
            }

            if (line.length() > sizeof(buffer)-1)
            {
                break;
            }
            memset(buffer, 0, sizeof(buffer));
            strcpy(buffer, line.c_str());

            if (!DataRecovery(buffer))
            {
                break;
            }
        }
        file.close();
    }
    return 0;
}

