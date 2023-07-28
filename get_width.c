#include "main.h"
/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: width or -1 if invalid.
 */
int get_width(const char *format, int *i, va_list list)
{
    int width = 0;
    int curr_i = *i + 1;
    while (format[curr_i] != '\0')
    {
        if (format[curr_i] == '*')
        {
            width = va_arg(list, int);
            if (width < 0) // Handle negative width as an error
                return -1;
            (*i) = curr_i; // Update the current index
            return width;
        }
        else if (is_digit(format[curr_i]))
        {
            width = width * 10 + (format[curr_i] - '0');
        }
        else
        {
            break;
        }
        curr_i++;
    }
    (*i) = curr_i - 1;
    return (width > 0) ? width : -1; // Return -1 if width is not valid
}
