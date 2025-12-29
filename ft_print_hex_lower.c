#include "ft_printf.h"
#include <stdlib.h>

int	ft_print_hex_lower(va_list *args)
{
	unsigned int	n;
	char			*hex_str;
	int				len;

	n = va_arg(*args, unsigned int);
	hex_str = ft_ultoa_base((unsigned long)n, 0);
	if (!hex_str)
		return (0);
	len = ft_strlen(hex_str);
	ft_putstr(hex_str);
	free(hex_str);
	return (len);
}

