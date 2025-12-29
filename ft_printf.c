#include "ft_printf.h"

static int	ft_handle_integer_spec(char spec, va_list *args)
{
	if (spec == 'd' || spec == 'i')
		return (ft_print_int(args));
	if (spec == 'u')
		return (ft_print_unsigned(args));
	if (spec == 'x')
		return (ft_print_hex_lower(args));
	if (spec == 'X')
		return (ft_print_hex_upper(args));
	return (0);
}

static int	ft_handle_format_specifier(char spec, va_list *args)
{
	if (spec == 'c')
		return (ft_print_char(args));
	if (spec == 's')
		return (ft_print_string(args));
	if (spec == 'p')
		return (ft_print_pointer(args));
	if (spec == '%')
		return (ft_print_percent());
	if (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'x' || spec == 'X')
		return (ft_handle_integer_spec(spec, args));
	return (ft_putchar('%') + (spec ? ft_putchar(spec) : 0));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_handle_format_specifier(format[i], &args);
		}
		else
			count += ft_putchar(format[i]);
		if (format[i])
			i++;
	}
	va_end(args);
	return (count);
}

