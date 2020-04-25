CFLAGS    = -Wall -Wextra -Werror -g

SRCS = srcs/print_d.c \
			srcs/print_s.c \
			srcs/print_u.c \
			srcs/print_x.c \
			srcs/print_c.c \
			srcs/print_p.c \
			srcs/print_pourcent.c \
			ft_printf.c \
			srcs/ft_printf_utils.c

HEADER = ft_printf.h	

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $^

%.o : %.c
	gcc -o $@ -c $< $(CFLAGS) -I $(HEADER)

clean::
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
