CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = ft_printf
SRCS = ft_printf.c  \
	   flag.c \
	   print.c \
	   ft_strchr.c \
	   ft_strlen.c \
	   ft_putstr.c \
	   ft_itoa.c \
	   ft_isdigit.c \
	   ft_putchar.c \
	   putstr_len_fill.c \
	   ft_atoi.c

OBJS = $(SRCS:.c=.o)

%.o: %.c 
	$(CC) -g -c -o $@ $< 

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) -g

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

