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

#define NUMBER_OF_LETTERS   26
#define INVALID_POSITION    -1
#define REPEATED_CHARACTER  -2

char FirstNonRepeatedCharacter(string line)
{
    int smallLetters[NUMBER_OF_LETTERS];
    int capitalLetters[NUMBER_OF_LETTERS];
    
    // initialize;
    for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    {
        smallLetters[i] = INVALID_POSITION;
        capitalLetters[i] = INVALID_POSITION;
    }

    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] >= 'A' && line[i] <= 'Z')
        {
            if (capitalLetters[line[i] - 'A'] == INVALID_POSITION)
            {
                capitalLetters[line[i] - 'A'] = i;
            }
            else if (capitalLetters[line[i] - 'A'] != REPEATED_CHARACTER)
            {
                capitalLetters[line[i] - 'A'] = REPEATED_CHARACTER;
            }
        }

        else if (line[i] >= 'a' && line[i] <= 'z')
        {
            if (smallLetters[line[i] - 'a'] == INVALID_POSITION)
            {
                smallLetters[line[i] - 'a'] = i;
            }
            else if (smallLetters[line[i] - 'a'] != REPEATED_CHARACTER)
            {
                smallLetters[line[i] - 'a'] = REPEATED_CHARACTER;
            }

        }
        else
        {
            return '\0';
        }
    }

    int firstPosition = 0xFFFFFF;

    for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    {
        if (smallLetters[i] != INVALID_POSITION && smallLetters[i] != REPEATED_CHARACTER)
        {
            if (smallLetters[i] < firstPosition )
            {
                firstPosition = smallLetters[i];
            }
        }

        if (capitalLetters[i] != INVALID_POSITION && capitalLetters[i] != REPEATED_CHARACTER)
        {
            if (capitalLetters[i] < firstPosition)
            {
                firstPosition = capitalLetters[i];
            }
        }
    }

    if (firstPosition == -1)
    {
        return '\0';
    }
    return line[firstPosition];
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
            cout << FirstNonRepeatedCharacter(line) << endl;
        }
        file.close();
    }
    return 0;
}

