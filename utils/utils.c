#include <stdio.h>

int size_of(char *string)
{
    /*
    Summery:
        returns size of given string

    Purpose:
        find the length of a string

    Example:
        >>> char * myString = "myString";
        >>> size_of(myString);
        (int)8
    */
    int count = 0;
    char s = string[0];
    while (s != '\0')
    {
        s = string[count];
        count++;
    }
    return count - 1;
}