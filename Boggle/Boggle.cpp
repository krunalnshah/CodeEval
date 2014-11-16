// Boggle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stdio.h"
#include "windows.h"

char array[][4] = { 
        { 'T', 'K', 'A', 'G' }, 
        { 'U', 'O', 'B', 'J' }, 
        { 'O', 'K', 'E', 'B' }, 
        { 'P', 'I', 'S', 'S' } };

bool map[4][4];
bool FindWord(char* curArray, int length, char* target, int targetLength, int xIndex, int yIndex, int position)
{
    bool retVal = true;
    if (position == targetLength)
    {
        curArray[position] = '\0';
        if (!strcmp(curArray, target))
        {
            return true;
        }
        return false;
    }

    if (xIndex < 0 || yIndex < 0 || xIndex  > 3 || yIndex > 3)
    {
        return false;
    }

    if (map[xIndex][yIndex])
    {
        return false;
    }

    
    curArray[position] = array[xIndex][yIndex];
    map[xIndex][yIndex] = true;
    if (FindWord(curArray, length, target, targetLength, xIndex + 1, yIndex, position + 1))
    {
        return true;
    }
    else
    {
        if (xIndex  + 1 < 4)
        map[xIndex + 1][yIndex] = false;
    }

    if (FindWord(curArray, length, target, targetLength, xIndex, yIndex+1, position + 1))
    {
        return true;
    }
    else
    {
        if (yIndex + 1 < 4)
        map[xIndex][yIndex + 1] = false;
    }

    if (FindWord(curArray, length, target, targetLength, xIndex - 1, yIndex, position + 1))
    {
        return true;
    }
    else
    {
        if (xIndex - 1 >= 0)
        map[xIndex - 1][yIndex] = false;
    }

    if (FindWord(curArray, length, target, targetLength, xIndex, yIndex - 1, position + 1))
    {
        return true;
    }
    else
    {
        if (yIndex - 1 >= 0)
        map[xIndex][yIndex - 1] = false;
    }

    return false;


}

void ResetBitMap()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            map[i][j] = false;
        }
    }
}

bool FindWord(char* word)
{
    char arr[256];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ResetBitMap();
            if (FindWord(arr, 256, word, strlen(word), i, j, 0))
            {
                return true;
            }
        }
    }
}

int _tmain(int argc, _TCHAR* argv[])
{

    FindWord("ABOUT");
	return 0;
}

