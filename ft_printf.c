#include "ft_printf.h"

static int print_variable(va_list var, const char type)
{
	int count;

	count = 0;
	if (type == 'c' || type == 's')
		count = manage_char(var, type);
	else if (type == 'd' || type == 'i')
		ft_putnbr_count(va_arg(var, long long), &count);
	else if (type == 'u')
		ft_putnbr_base(va_arg(var, unsigned int), "0123456789", 10, &count);
	else if (type == 'x')
		ft_putnbr_base(va_arg(var, unsigned int), "0123456789abcdef", 16, &count);
	else if (type == 'X')
		ft_putnbr_base(va_arg(var, unsigned int), "0123456789ABCDEF", 16, &count);
	else if (type == 'p')
			count += print_pointer((unsigned long) va_arg(var, void *));
	else if (type == '%')
	{
		ft_putchar_fd('%', 1);
		count++;
	}
    return (count);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int     count;
    int     add_count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				add_count = print_variable(args, *format);
		}
		else
			add_count = write(1, format, 1);
		++format;
        if (add_count == -1)
            count = -1;
        if (count != -1)
            count += add_count;
	}
	va_end(args);
	return (count);
}
