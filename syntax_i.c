#include "holberton.h"

/**
 * syntax_i - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @f_list: A list of all the posible functions.
 * @arg_list: A list containing all the argumentents passed to the program.
 * Return: A total count of the characters printed.
 */
int syntax_i(const char *format, mod_sf f_list[], va_list arg_list)
{
	int i, j, r_val, output_chars;

	output_chars = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			/*Iterates through struct to find the right func*/
			for (j = 0; f_list[j].signs != NULL; j++)
			{
				if (format[i + 1] == f_list[j].signs[0])
				{
					r_val = f_list[j].f(arg_list);
					if (r_val == -1)
						return (-1);
					output_chars += r_val;
					break;
				}
			}
			if (f_list[j].signs == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_pchar(format[i]);
					_pchar(format[i + 1]);
					output_chars = output_chars + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_pchar(format[i]); /*call the write function*/
			output_chars++;
		}
	}
	return (output_chars);
}
