// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
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

int FindSum(int count)
{
    if (count == 0)
    {
        return 0;
    }

    int i = 1;
    int sum = 2;
    int number = 3;

    while (i < count)
    {
        if (IsPrime(number))
        {
            i++;
            sum += number;
        }
        number += 2;
    }
    return sum;
}

bool CompareBitPositions(int number, int bitposition1, int bitposition2)
{
    int lhs = (number & (1 << bitposition1-1)) >> (bitposition1 - 1);
    int rhs = (number & (1 << bitposition2-1)) >> (bitposition2 - 1);
    if (lhs == rhs)
    {
        //cout << "true";
        return true;
    }
    else
    {
        return false;
    }
    //cout << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
    //int sum = FindSum(1000);
    bool retval = CompareBitPositions(86, 2, 3);
    retval = CompareBitPositions(125, 1, 2);
    
	return 0;
}

