/*
** EPITECH PROJECT, 2022
** mini printf
** File description:
** a simple version of printf
*/

#include <stdarg.h>
#include "../../include/my.h"

static void minima_printf (int i, char flag, va_list list)
{
    if (flag == 'd' || flag == 'i')
        my_put_nbr(va_arg(list, int));
    if (flag == 's')
        my_putstr(va_arg(list, char *));
    if (flag == '%')
        my_putchar('%');
}

int mini_printf(const char *format, ...)
{
    va_list list;
    char flag;
    int i;

    va_start(list, format);
    for (i = 0; format[i] != '\0'; i ++) {
        if (format[i] != '%')
            my_putchar(format[i]);
        if (format[i] == '%') {
            flag = format[i + 1];
            i ++;
        }
        minima_printf(i, flag, list);
        flag = '\0';
    }
    va_end(list);
    return (0);
}
