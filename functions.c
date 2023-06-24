#include "main.h"
/**
 * _putchar - writes a character c to stdout
 * @c: the character to print
 * Return: 1 for success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * printf_char - writes a char to stdout
 * @vars: a va_list containing the char to write
 * Return: 1 for success
 */
int printf_char(va_list vars)
{
	return (_putchar((char)va_arg(vars, int)));
}

/**
 * printf_percent - writes percent sign to stdout
 * @vars: a va_list containing percent sign
 * Return: 1 for success
 */
int printf_percent(va_list vars)
{
	(void) vars;

	return (_putchar('%'));
}
/**
 * printf_string - writes a string to stdout
 * @vars: a va_list cointaining the string to write
 * Return: the number of bytes writen or -1 if fails
 */
int printf_string(va_list vars)
{
	int length, i;
	char *str;

	str = va_arg(vars, char *);

	if (!str)
		str = "(null)";
	length = 0;
	for (i = 0; str[i]; i++)
		length += _putchar(str[i]);
	return (length);
}
