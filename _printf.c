#include "main.h"
/**
 * _printf - my printf
 * @format: format
 * Return: number of printed chars or -1 otherwise
 */
int _printf(const char *const format, ...)
{
	type m[] = {
		{"%s", printf_string},
		{"%c", printf_char},
		{"%%", printf_percent},
		{"%i", print_int},
		{"%d", print_double},
		{NULL, NULL}
	};
	va_list arg;
	int i = 0, count = 0, j = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		while (format[i] == '%')
		{
			if (format[i + 1] == m[j].form[1])
			{
			count += m[j].f(arg);
			i += 2;
			}
			j++;
		}
		count += _putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
