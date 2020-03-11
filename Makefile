CFLAGS    = -Wall -Wextra -Werror

SRCS = ./srcs/*.c

HEADER = ./ft_printf.h	

OBJS = $(SRCS:.c=.o)

NAME = ft_printf.a

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
