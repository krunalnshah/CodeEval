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

bool ValidCharacter(char character)
{
    if (character >= 'a' && character >= 'z')
        return true;
    else if (character == ' ')
        return true;
    else
        return false;
}

char* BalancedSmiley(string line)
{    
    if (line.length() == 0)
    {
        return "YES";
    }
    int countBraces = 0;
    int happySmiley = 0;
    int sadSmiley = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (ValidCharacter(line[i]))
        {
            happySmiley = 0;
            sadSmiley = 0;
            continue;
        }
        
        // smiley detection
        if (line[i] == ':')
        {
            if (i + 1 < line.length())
            {
                if (line[i + 1] == ')' )
                {
                    happySmiley++;
                    i++;
                }
                else if (line[i + 1] == '(')
                {
                    sadSmiley++;
                    i++;
                }
            }
        }
        else if (line[i] == ')')
        {
            countBraces--;
            
        }
        else if (line[i] == '(')
        {
            countBraces++;
        }
        else
        {
            return "NO";
        }            
    }
    
    if (countBraces == 0)
    {
        return "YES";
    }
    else if (countBraces + happySmiley - sadSmiley == 0)
    {
        return "YES";
    }
    
    return "NO";
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
            cout << BalancedSmiley(line) << endl;
        }
        file.close();
    }
    return 0;
}


