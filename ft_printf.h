#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(va_list *args);
int	ft_print_string(va_list *args);
int	ft_print_pointer(va_list *args);
int	ft_print_int(va_list *args);
int	ft_print_unsigned(va_list *args);
int	ft_print_hex_lower(va_list *args);
int	ft_print_hex_upper(va_list *args);
int	ft_print_percent(void);

// Utility functions
size_t	ft_strlen(const char *s);
int	ft_putchar(char c);
int	ft_putstr(char *s);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_ultoa_base(unsigned long n, int uppercase);

#endif

