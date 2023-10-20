#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);

/**
 * get_int - Converts an integer to a character pointer
 * pointing to a new string.
 *
 * @num: The integer to convert to a string.
 *
 * This function takes an integer as input and converts it into a character
 * pointer pointing to a newly created string representation of the integer.
 * It allocates memory for the string and gracefully handles any memory
 * allocation errors, returning NULL if allocation fails. The resulting string
 * can be used for various text-based operations or printing.
 *
 * Return: A character pointer to the newly created string,
 * or NULL if malloc fails.
 */

char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++;
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - Compute the absolute value of an integer.
 * @i: Input integer to find the absolute value of.
 *
 * Return: An unsigned integer representing the absolute value of i.
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - Calculate the minimum buffer length for representing an
 *                   unsigned integer in a specific base.
 *
 * This function calculates the minimum buffer length required to represent an
 * unsigned integer in a specified base. The resulting buffer does not include
 * a null terminator.
 *
 * @num: The unsigned integer for which the buffer length is calculated.
 * @base: The base used for the number representation in the buffer.
 *
 * Return: The minimum buffer length needed for the representation.
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * convertNumberToBase - Convert a number to its string representation in
 * a specified base.
 *
 * This function takes a positive integer 'num'
 * and converts it to a string in the
 * given 'base', filling the 'buff' buffer with the result.
 * The function supports
 * bases from 2 to 36. The result is stored in 'buff',
 * and 'buff_size' determines
 * the maximum number of characters that can be written to the buffer.
 *
 * @num: The number to convert to a string in the specified base.
 * @base: The base to convert the number to (2 to 36).
 * @buff: The buffer to store the string representation of the number.
 * @buff_size: The size of the buffer in bytes.
 *
 * Return: This function does not return a value, but it fills the 'buff' with
 * the converted number as a string.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
