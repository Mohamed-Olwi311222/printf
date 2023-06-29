#include "main.h"
#include <math.h>
/**
 * print_int - prints an int
 * @vars: variable to hold an int
 * Return: the count of digits
 */
int print_int(va_list vars)
{
	char *str;
	int num = va_arg(vars, int), count = 0, i;
	int size = (int) log10(abs(num));

	if (num < 0)
		count += _putchar('-');
	/*
	 * 12345 in 1st line becomes 1234 % 10 = 5 then it is stored in str
	 * in 2nd line 12345 => 1234
	 * and repeates
	 */
	str = malloc(1 + size);
	if (str == NULL)
		return (0);

	do {
		str[count++] = num % 10 + '0';
		num /= 10;
	} while (num != 0);

	for (i = count - 1; i >= 0; i--)
		_putchar(str[i]);
	free(str);
	return (count);
}
/**
 * print_double - prints a double
 * @vars: variable to hold a double
 * Return: the count of digies
 */
int print_double(va_list vars)
{
	double num = va_arg(vars, double), decimal, size;
	int count = 0, i, digit, int_part;
	char *str_int;

	if (num < 0)
	{
		count += _putchar('-');
		num = -num;
	}

	int_part = (int) num;
	size = log10(abs(int_part));
	str_int = malloc(1 + size);
	if (str_int == NULL)
		return (0);

	do {
		str_int[count++] = int_part % 10 + '0';
		int_part /= 10;
	} while (int_part >= 1);

	for (i = count - 1; i >= 0; i--)
		_putchar(str_int[i]);

	count += _putchar('.');

	decimal = num - (int) num;

	for (i = 0; i < 15; i++)
	{
		decimal *= 10;
		digit = (int) decimal + ((decimal - (int) decimal) >= 0.5);
		count += _putchar('0' + digit);
		decimal -= digit;
	}
	free(str_int);
	return (count);

}
