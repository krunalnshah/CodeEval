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

bool IsPrime(int number)
{
    for (int i = 3; i < number; i += 2)
    {
        if (number%i == 0)
        {
            return false;
        }
    }
    return true;
}

int CalculatePrimeNumbers(unsigned int maxNumber, unsigned int* primeNumbers, int length)
{
    int j = 0;
    int count = 0;
    primeNumbers[j] = 2;
    j++;
    for (unsigned int i = 3; i < maxNumber; i+=2)
    {
        if (IsPrime(i))
        {
            primeNumbers[j] = i;

            j++;
            if (j > length)
            {
                return -1;
            }
        }
    }

    return j;
}

void PrintPrimeNumbers(unsigned int number, unsigned int* primeNumbers, int length)
{
    int i = 0;
    bool firstCharacterPrinted = false;
    while (number > primeNumbers[i] && i < length)
    {
        if (!firstCharacterPrinted)
        {
            cout << primeNumbers[i];
            firstCharacterPrinted = true;
        }
        else
        {
            cout << ","  <<primeNumbers[i];
        }        
        i++;
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
    unsigned int maxNumber = 0;
    unsigned int currentNumber = 0;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.length() == 0)
            {
                continue;
            }
            currentNumber = atoi(line.c_str());
            if (currentNumber > maxNumber)
            {
                maxNumber = currentNumber;
            }
        }
        file.close();
    }

    unsigned int primeNumbers[4096];

    int count = CalculatePrimeNumbers(maxNumber, primeNumbers, 4096);


    ifstream inFile2(argv[1]);
    if (inFile2.is_open())
    {
        while (getline(inFile2, line))
        {
            if (line.length() == 0)
            {
                continue;
            }

            currentNumber = atoi(line.c_str());
            PrintPrimeNumbers(currentNumber, primeNumbers, count);
        }
        inFile2.close();
    }
    return 0;
}




