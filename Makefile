NAME 	= libftprintf.a
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
LIB 	= ar -rcs

INCLUDE = ft_printf.h

SRCS 	= ft_printf.c printf_utlis.c

OBJS 	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS) $(INCLUDE)
		$(LIB) $(NAME) $(OBJS)

%.o : %.c ${INCLUDE}
		$(CC) -c -o $@ $<

clean:
		rm -rf $(OBJS)

fclean:		clean
		rm -rf $(NAME)

re:			fclean all