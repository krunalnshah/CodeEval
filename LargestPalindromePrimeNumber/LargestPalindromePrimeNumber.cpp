// LargestPalindromePrimeNumber.cpp : Defines the entry point for the console application.
//
#include "tchar.h"
#include "stdio.h"
#include "stdlib.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


bool IsPalindrome(char* string)
{
    if (!string)
    {
        return false;
    }

    char* end = string;
    char* start = string;

    while (*end++)
    {
    }
    end--;
    end--;

    while (start < end)
    {
        if (*start++ != *end--)
        {
            return false;
        }
    }

    return true;
}

bool IsPalindrome(int number)
{
    char num[12];
    sprintf(num, "%d", number);
    return IsPalindrome(num);
}

bool IsPrimeNumber(int number)
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

int FindLargestPrimePalindromeNumber(int max)
{
    if ((max == 0) || (max == 1))
    {
        return -1;
    }

    if (max == 2)
    {
        return 2;
    }

    if (max % 2 == 0)
    {
        max--;
    }

    while (max > 0)
    {
        if (IsPalindrome(max))
        {
            if (IsPrimeNumber(max))
            {
                return max;
            }
        }
        max -= 2;
    }

    return -1;
}

int _tmain(int argc, _TCHAR* argv[])
{
    int num = FindLargestPrimePalindromeNumber(1000);
    
        return 0;
}

