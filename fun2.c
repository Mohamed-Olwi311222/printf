#include "main.h"
/**
 * my_log - returns the log of @x
 * @x: double type
 * Return: return the log(x)
 */
double my_log(double x)
{
	double y = 1.0;
	double sum = 0.0;
	int i;

	if (x <= 0.0)
	{
		return (NAN);
	}

	for (i = 0; i < 100; i++)
	{
		sum += y / (2.0 * i + 1.0);
		y *= (x - 1.0) / (x + 1.0) * (x - 1.0) / (x + 1.0);
	}
	return (2.0 * sum);
}
/**
 * my_log10 - return the log10 of @x
 * @x: double type
 * Return: log10(x)
 */
double my_log10(double x)
{
	return (my_log(x) / my_log(10));
}
/**
 * print_int - prints an int
 * @vars: variable to hold an int
 * Return: the count of digits
 */
int print_int(va_list vars)
{
	char *str;
	int num = va_arg(vars, int), count = 0, i;

	if (num < 0)
		count += _putchar('-');
	/*
	 * 12345 in 1st line becomes 1234 % 10 = 5 then it is stored in str
	 * in 2nd line 12345 => 1234
	 * and repeates
	 */
	str = malloc(1 + my_log10(abs(num)));
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
	double num = va_arg(vars, double), decimal;
	int count = 0, i, digit, int_part;
	char *str_int;

	if (num < 0)
	{
		count += _putchar('-');
		num = -num;
	}

	int_part = (int) num;
	str_int = malloc(1 + my_log10(abs(int_part)));
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
