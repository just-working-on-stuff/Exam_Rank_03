#include <unistd.h>
#include <stdarg.h>

void ft_putstr(char *str, int *i)
{
    if (!str)
        str = "(null)";
    while (*str)
    {
        write(1, str++, 1);
        (*d)++;
    }
}

void ft_putnum(int num, int *d)
{
    char c;
    if (num == -2147483648)
    {
        ft_putstr("-2147483648", d);
        return;
    }
    if (num < 0)
    {
        write(1, "-", 1);
        (*d)++;
        num = -num;
    }
    if (num > 9)
        ft_putnum(num / 10, d);
    c = (num % 10) + '0';
    write(1, &c, 1);
    (*d)++;
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int d = 0;
    va_start(ap, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            if (*format == s)
                ft_putstr(va_arg(ap, char *), &d);
            else if (*format == 'd')
                ft_putnum(va_arg(ap, int), &d);
            else if (*format == 'x')
                ft_puthex(va_arg(ap, unsigned int), &d);
            else
            {
                write(1, format, 1);
                d++;
            }
            else
            {
                write(1, format, 1);
                d++;
            }
            format++;
        }
    }
    va_end(ap);
    return (d);
}