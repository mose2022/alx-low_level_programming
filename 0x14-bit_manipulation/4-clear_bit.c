#include "main.h"

/**
 * clear<S-F12>bit - Sets value of bit to 0 at given index.
 * @n: Unsigned int.
 * @index: Bit index.
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8) 
    {
        return (-1);
    }

    if ((*n >> index) & 1) 
    {
        *n ^= (1UL << index); 
    }

    return (1);
}
