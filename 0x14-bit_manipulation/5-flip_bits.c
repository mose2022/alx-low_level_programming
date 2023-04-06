#include "main.h"

/**
 * flip_bits - Returns number of bits.
 * @n: First number.
 * @m: Second number.
 * Return: Number of bits flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int nbits = 0;
	unsigned int i;

	for (i = 0; i < 64; i++)
	{
		if ((n & 1) != (m & 1))
			nbits++;

		n >>= 1;
		m >>= 1;
	}

	return (nbits);
}
