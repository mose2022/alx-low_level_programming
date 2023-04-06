#include "main.h"

/**
 * get_endianness - Checks Endianness.
 * Return: For big endian, 0.
 * For little endian, 1.
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
