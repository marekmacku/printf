#include "ft_printf.h"
#include <stdlib.h>

int	ft_print_pointer(va_list *args)
{
	void			*ptr;
	unsigned long	addr;
	char			*hex_str;
	int				len;

	ptr = va_arg(*args, void *);
	if (!ptr)
	{
		ft_putstr("0x0");
		return (3);
	}
	addr = (unsigned long)ptr;
	hex_str = ft_ultoa_base(addr, 0);
	if (!hex_str)
		return (0);
	ft_putstr("0x");
	ft_putstr(hex_str);
	len = ft_strlen(hex_str) + 2;
	free(hex_str);
	return (len);
}

