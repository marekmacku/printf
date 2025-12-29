#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret_ft;
	int	ret_std;

	ret_std = printf(" %c %c %c \n", '5', 0, '1');
	ret_ft = ft_printf(" %c %c %c ", '1', 0, '1');
	printf("ft_printf returned: %d, printf returned: %d\n", ret_ft, ret_std);
	return (0);
}
