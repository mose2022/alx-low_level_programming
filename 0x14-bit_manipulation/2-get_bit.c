#include "main.h"

/**
 * get_bit - Returns the value of a bit.
 * @n: Unsigned int.
 * @index: Bit index.
 * Return: The value of the bit at index.
 */
int get_bit(unsigned long int n, unsigned int index)
{
    unsigned int j;

    if (index >= 64)
    {
        return -1;
    }

    for (j = 0; j <= 63; j++)
    {
        if (index == j)
        {
            return n & 1;
        }

        n >>= 1;

        if (n == 0 && j < 63)
        {
            return 0;
        }
    }

    return (-1);
}
