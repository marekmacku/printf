#include "ft_printf.h"
#include <stdlib.h>

int	ft_print_int(va_list *args)
{
	int		n;
	char	*str;
	int		len;

	n = va_arg(*args, int);
	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

