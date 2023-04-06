#include "main.h"

/**
 * binary_to_unit - covert a binary number.
 * @b: binary number.
 * Return: converted number.
 */
unsigned int binary_to_uint(const char *b)
{
    unsigned int result;
    int len, base;

    if (!b)
        return (0);

    result = 0;

    for (len = 0; b[len] != '\0'; len++)
	    ;

    for (len--, base = 1; len >= 0; len--, base *= 2)
    {
        if (b[len] != '0' && b[len] != '1')
        {
            return (0);
        }

        if (b[len] & 1)
        {
            result += base;
        }
    }

    return (result);
}
