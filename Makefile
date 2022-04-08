SRCS		= lis .c \
		parsing.c \
		pos.c \
		push_swap_utils.c \
		push_swap_utils2.c \
		push_swap.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		stackpush.c 

OBJS			= $(SRCS:.c=.o)

NAME			= push_swap

NAMECHECKER		= checker


CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f

CC				= gcc

AR				= ar rcs

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L.

$(NAMECHECKER):
				$(CC) $(CFLAGS) -o $(NAMECHECKER) -L.

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(NAMECHECKER)

re:				fclean all

.PHONY:			all clean fclean c.o re
