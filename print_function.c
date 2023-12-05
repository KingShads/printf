#include "main.h"

/**
 * _printf - produces putp0ut according to format
 * @format: character string argument
 * Return: number of characters print
 */

int _printf(const char *format, ...)
{
	int chara_print = 0;
	va_list args_list;

	if (format == NULL)
		return (-1);
	va_start(args_list, format);
	while (*format)
	{
		if  (*format != '%')
		{
			write(1, format, 1);
			chara_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				chara_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args_list, int);

				write(1, &c, 1);
				chara_print;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args_list, char *);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				chara_print += str_len;
			}
		}
		format++;
	}
	va_end(args_list);
	return (chara_print);
}
