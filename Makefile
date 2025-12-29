# Makefile for ft_printf

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	ft_utils.c \
	ft_print_char.c \
	ft_print_string.c \
	ft_print_pointer.c \
	ft_print_int.c \
	ft_print_unsigned.c \
	ft_print_hex_lower.c \
	ft_print_hex_upper.c \
	ft_print_percent.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) idk

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) main.c -L. -lftprintf -o idk

.PHONY: all clean fclean re test

