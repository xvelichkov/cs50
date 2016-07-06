/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"
#include <stdio.h>

bool binarySearch(int value, int values[], int start, int end)
{
    if(end < start)
    {
        return false;
    }
    else
    {
        int middle = (start + end) / 2;
        if(value > values[middle])
        {
            return binarySearch(value, values, middle+1, end);
        }
        else if(value < values[middle])
        {
            return binarySearch(value, values, start, middle-1);
        }
        else
        {

            return true;
        }
    }

    return false;
}


/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    return binarySearch(value, values, 0, n-1);
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int num = values[i];
        for(int j = i; j >= 0; j--)
        {
            if(values[j-1] > num)
            {
                values[j] = values[j-1];
            }
            else
            {
                values[j] = num;
                break;
            }
        }
    }
    return;
}