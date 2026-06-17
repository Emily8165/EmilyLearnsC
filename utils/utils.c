#include <stdio.h>
#include <stdlib.h>

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

char *bitwise_and(char *first, char *second)
{
    int size_of_first = size_of(first);
    char *value = malloc(sizeof(char) * size_of_first);
    for (int i = 0; i < size_of_first; i++)
    {
        if (first[i] == second[i])
        {
            value[i] = '1';
        }
        else
        {
            value[i] = '0';
        }
    }
    return value;
}

char *bitwise_not(char *first, char *second)
{
    int size_of_first = size_of(first);
    char *value = malloc(sizeof(char) * size_of_first);
    for (int i = 0; i < size_of_first; i++)
    {
        if (first[i] == second[i])
        {
            value[i] = '0';
        }
        else
        {
            value[i] = '1';
        }
    }
    return value;
}

char *bitwise_or(char *first, char *second)
{
    int size_of_first = size_of(first);
    char *value = malloc(sizeof(char) * size_of_first);
    for (int i = 0; i < size_of_first; i++)
    {
        if (first[i] == second[i])
        {
            value[i] = first[i];
        }
        else if (value[i] == '1')
        {
            value[i] = '0';
        }
        else
        {
            value[i] = '1';
        }
    }
    return value;
}

char *bitwise_xor(char *first, char *second)
{
    int size_of_first = size_of(first);
    char *value = malloc(sizeof(char) * size_of_first);
    for (int i = 0; i < size_of_first; i++)
    {
        if (first[i] != second[i])
        {
            value[i] = '1';
        }
        else
        {
            value[i] = '0';
        };
    }
    return value;
}

int main()
{
    printf("%s", bitwise_xor("0010", "1010"));
}