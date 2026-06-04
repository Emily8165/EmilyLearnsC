#include <stdio.h>
#include <stdlib.h>
#include "math_lib/math_lib.h"
#include "utils/utils.h"

int hexlet_to_int(char letter)
{
    /*
    Summery:
        returns given char as an integer

    Purpose:
        allows for mathmatical manipulation of chars.

    Example:
        >>> hexlet_to_int('A')
        (int)10
    */
    switch (letter)
    {
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
    default:
        return (int)letter - '0';
        ;
    }
}

char int_to_hex(int val)
{
    /*
    Summery:
        returns char value of int as hex

    Purpose:
        converts digit into a hex value

    Example:
        >>> char int_to_hex(10);
        'A'
        >>> char int_to_hex(1);
        '1'
    */
    if ((val >= 10) && (val <= 16))
    {
        return (char)val + 55;
    }
    else
    {
        return (char)val + 48;
    }
}

int hex_to_dec(char *hex)
{
    /*
    Summery:
        Converts given hex number into decimal

    Purpose:
        converting hex to decimal

    Example:
        >>> hex_to_dec("1A")
        (int)26
    */
    // hex_to_dec("1A") = 1 * (16 * 1) + 10 * (16 * 0) = 26
    int result = 0;
    int length = size_of(hex);
    int j = length - 1;
    for (int i = 0; i < length; i++)
    {
        result += hexlet_to_int(hex[i]) * power(16, j);
        j--;
    }
    return result;
}

char *_dec_to_hex(int dec, char *result, int iter)
{
    /*
    Summery:
        takes a decimal number, result to store the hex in and an iter count

    Purpose:
        called recursively to return the hex number, this number will be the wrong way around.

    Example:
        char *myString = (char *)malloc(1);
        >>> _dec_to_hex(2524, myString, 0);
        1F9
    */
    if (dec > 16)
    {
        result[iter] = int_to_hex(dec % 16);
        iter++;
        _dec_to_hex(dec / 16, result, iter);
    }
    else
    {
        result[iter] = int_to_hex(dec % 16);
    }
    return result;
}

char *dec_to_hex(int dec)
{
    /*
    Summery:
        converts decimal number to hex

    Purpose:
        converting decimal to hex

    Example:
        >>> dec_to_hex(2524)
        9F1
    */
    char *myString = (char *)malloc(1);
    char *hex = _dec_to_hex(dec, myString, 0);
    int size = size_of(hex);
    char *result = (char *)malloc(size);
    int j = size;
    for (int i = 0; i < size; i++)
    {
        j--;
        int val = (int)hex[i];
        if ((48 <= val && val <= 57) || (65 <= val && val <= 70))
        {
            result[i] = hex[j];
        }
    }
    return result;
}