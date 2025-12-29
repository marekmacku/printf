#include "ft_printf.h"

int	ft_print_string(va_list *args)
{
	char	*str;
	int		len;

	str = va_arg(*args, char *);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(str);
	ft_putstr(str);
	return (len);
}

