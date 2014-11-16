// CalculateBeautyOfString.cpp : Defines the entry point for the console application.
//


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
#include <string>

using namespace std;

#define NUMBER_OF_LETTERS 26
class Letter
{
public:
    int instances;
    int value;
    char character;

    Letter()
    {
        instances = 0;
        value = 0;
        character = '\0';
    }
#if 0
    Letter operator=(const Letter& a)
    {
        character = a.character;
        instances = a.instances;
        value = a.value;
        return *this;
    }
#endif
    bool operator== (Letter a)
    {
        if (character == a.character)
        {
            return true;
        }
        return false;
    }

};


bool ScanString(string line, Letter* letters, size_t numberOfLetters)
{
    if (line.length() == 0 || !letters || (numberOfLetters != NUMBER_OF_LETTERS))
    {
        return false;
    }

    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] >= 'A' && line[i] <= 'Z')
        {
            letters[line[i] - 'A'].instances++;
        }

        if (line[i] >= 'a' && line[i] <= 'z')
        {
            letters[line[i] - 'a'].instances++;
        }           
    }
    return true;
}

Letter Max(Letter leftLetter, Letter rightLetter)
{
    if (leftLetter.instances >= rightLetter.instances)
    {
        return leftLetter;
    }
    return rightLetter;
}

void MergeSort(Letter* letters, int start, int end, Letter* scratch)
{
    // base case 1 element
    if (end == start + 1)
    {
        return;
    }
    int length = end - start;
    int midpoint = length / 2;
    int l = start;
    int r = start + (length / 2);


    MergeSort(letters, start, start + midpoint, scratch);
    MergeSort(letters, start + midpoint, end, scratch);

    for (int i = start; i < end; i++)
    {
        if ((Max(letters[l], letters[r]) == letters[l] || (r == end)) && (l <  (start+ midpoint)))
        {
            scratch[i] = letters[l];
            l++;
        }
        else
        {
            scratch[i] = letters[r];
            r++;
        }
    }

    for (int i = start; i < end; i++)
    {
        letters[i] = scratch[i];
    }

}

bool sort(Letter* letters, int size)
{
    if (size == 0 || !letters)
    {
        return false;
    }

    Letter* scratch = new Letter[size];

    if (!scratch)
    {
        return false;
    }
    
    MergeSort(letters, 0, size, scratch);

    delete[] scratch;

    return true;
}


bool AssignValue(Letter* letters, int size)
{
    if (!letters || (size != NUMBER_OF_LETTERS))
    {
        return false; 
    }

    int value = NUMBER_OF_LETTERS;
    for (int i = 0; i < size; i++)
    {
        if (letters[i].instances == 0)
        {
            break;
        }
        letters[i].value = value--;
    }
    return true;
}

int CalculateBeauty(Letter* letters, int size)
{
    if (!letters || (size != NUMBER_OF_LETTERS))
    {
        return -1;
    }

    int beautyValue = 0;
    for (int i = 0; i < size; i++)
    {
        if (letters[i].instances == 0)
        {
            break;
        }
        beautyValue += (letters[i].instances * letters[i].value);
    }

    return beautyValue;
}

int CalculateBeauty(string line)
{
    Letter letters[NUMBER_OF_LETTERS];

    for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    {
        letters[i].character = 'A' + i;
    }

    if (!ScanString(line, letters, NUMBER_OF_LETTERS))
    {
        return -1;
    }

    if (!sort(letters, NUMBER_OF_LETTERS))
    {
        return -1;
    }

    if(!AssignValue(letters, NUMBER_OF_LETTERS))
    {
        return -1;
    }

    return CalculateBeauty(letters, NUMBER_OF_LETTERS);
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

            cout << CalculateBeauty(line) << endl;
        }
        file.close();
    }
    return 0;
}


