#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct type - match the conversion specefier for printf
 * @form: type char pointer of the specifier
 * @f: pointer to the function for the conversion specefier
 */
typedef struct type
{
	char *form;
	int (*f)(va_list var);
} type;

int printf_string(va_list vars);
int printf_char(va_list vars);
int printf_percent(va_list vars);
int _putchar(char c);
int _printf(const char *format, ...);
#endif
