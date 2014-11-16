// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"

int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    return a;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}


static int kthSmallest(int list12[], int list23[], int k) {
    int list1[] = { 3, 4, 10, 23, 24, 45, 55, 56, 58, 60, 65 };
    int list2[] = { 3, 3, 3, 15, 16, 25, 28, 50, 70, 71, 72 };
    int listSize1 = 10;
    int listSize2 = 10;
    int startPos1 = 1;
    int startPos2 = 1;
    int endPos1 = k;
    int endPos2 = k;
    int size1 = k;
    int size2 = k;
    int lastPos1 = listSize1;
    int lastPos2 = listSize2;

    //// Edge case: k is out of bounds
    //if (k < 1 || k > listSize1 + listSize2) {
    //    return 0;
    //}

    //// Edge case: first list has length 0
    //if (listSize1 == 0) {
    //    return list2[k - 1];
    //}

    //// Edge case: second list has length 0
    //if (listSize2 == 0) {
    //    return list1[k - 1];
    //}

    while (size1 > 2 || size2 > 2) {
        //   while (startPos1 != lastPos1 || startPos2 != lastPos2)
        // {
        int mid1 = (startPos1 + endPos1) / 2;
        int mid2 = k - mid1;
        int val1;
        int val2;

        //if (mid1 > lastPos1) {
        //    val2 = list2[mid2 - 1];
        //    val1 = val2 + 1; // "Infinity"
        //}
        //else if (mid2 > lastPos2) {
        //    val1 = list1[mid1 - 1];
        //    val2 = val1 + 1; // "Infinity"
        //}
        //else
        {
            val1 = list1[mid1 - 1];
            val2 = list2[mid2 - 1];
        }

        // Modify start and end positions in binary search fashion
        if (val1 == val2) {
            return val1;
        }
        else if (val1 > val2) {
            endPos1 = mid1;
            startPos2 = mid2;
        }
        else {
            startPos1 = mid1;
            endPos2 = mid2;
        }

        size1 = endPos1 - startPos1 + 1;
        size2 = endPos2 - startPos2 + 1;
        lastPos1 = min(listSize1, endPos1);
        lastPos2 = min(listSize2, endPos2);
    }

    //if (k <= 2) {
    //    int val1 = min(list1[startPos1 - 1], list1[lastPos1 - 1]);
    //    int val2 = min(list2[startPos2 - 1], list2[lastPos2 - 1]);
    //    return (k == 1) ? min(val1, val2) : max(val1, val2);
    //}

    if (startPos1 == lastPos1) {
        int val1 = list1[startPos1 - 1];
        int val2 = list2[k - startPos1 - 1];
        return max(val1, val2);
    }

    if (startPos2 == lastPos2) {
        int val2 = list2[startPos2 - 1];
        int val1 = list1[k - startPos2 - 1];
        return max(val1, val2);
    }

    int max1 = max(list1[startPos1 - 1], list1[lastPos1 - 1]);
    int max2 = max(list2[startPos2 - 1], list2[lastPos2 - 1]);
    int min1 = min(max1, max2);

    return min1;
}


int _tmain(int argc, _TCHAR* argv[])
{
    int list1[] = { 3, 4, 10, 23, 45, 55, 56, 58, 60, 65 };
    int list2[] = { 3, 3, 3, 15, 16, 28, 50, 70, 71, 72 };
    int k = 11;
    int kSmallest = kthSmallest(list1, list2, k);
    return 0;
}

