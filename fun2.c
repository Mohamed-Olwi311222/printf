#include "main.h"
/**
 * print_int - prints an int
 * @vars: variable to hold an int
 * Return: the count of digits
 */
int print_int(va_list vars)
{
	char str[30];
	int num = va_arg(vars, int), count = 0, i;

	if (num < 0)
	{
		_putchar('-');
	}
	/*
	 * 12345 in 1st line becomes 1234 % 10 = 5 then it is stored in str
	 * in 2nd line 12345 => 1234
	 * and repeates
	 */
	do {
		str[count++] = num % 10 + '0';
		num /= 10;
	} while (num != 0);
	for (i = count - 1; i >= 0; i--)
		_putchar(str[i]);
	return (count);
}
