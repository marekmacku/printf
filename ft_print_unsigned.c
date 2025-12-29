#include "ft_printf.h"
#include <stdlib.h>

int	ft_print_unsigned(va_list *args)
{
	unsigned int	n;
	char			*str;
	int				len;

	n = va_arg(*args, unsigned int);
	str = ft_utoa(n);
	if (!str)
		return (0);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

