#include <stdio.h>
#include "math_lib.h"

int power(int x, int pow)
{
    /*
    Summery:
        returns x to the power of pow

    Purpose:
        a customer pow function that means we don't have to import a libary

    Example:
        >>> power(2, 3)
        8
    */
    if (pow == 0)
    {
        return 1;
    }
    int result = x;
    for (int i = 0; i < pow - 1; i++)
    {
        result = (result * x);
    }
    return result;
}