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
		{"%s", printf_char},
		{"%%", printf_percent},
	};
	va_list arg;
	int i = 0, count = 0, j = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		while (m[j].form[0] == format[i] && m[j].form[1] == format[i + 1])
		{
			count += m[j].f(arg);
			i += 2;
			break;
		}
		count += _putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
