#include "main.h"

/**
 * get_endianness - Checks Endianness.
 * Return: 0 for big endian, 1 for little endian.
 */
int get_endianness(void)
{
    int num = 1;
    char *ptr = (char *)&num;

    if (*ptr == 1)
        return 1;
    else
        return 0;
}
