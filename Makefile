SRCS		= checker_utils.c \
			  checker_utils2.c \
			  futur_pos.c \
			  get_next_line_utils.c \
			  get_next_line.c \
			  initialise.c \
			  lis.c \
			  little_sort.c \
			  parsing.c \
			  push_swap_utils.c \
			  push_swap.c \
			  push_swap_utils2.c \
			  push.c \
			  reverse_rotate.c \
			  rotate.c \
			  stackpush.c \
			  insertion_sort.c

BSRCS		= checker_utils.c \
			  checker_utils2.c \
			  checker.c \
			  futur_pos.c \
			  get_next_line_utils.c \
			  get_next_line.c \
			  initialise.c \
			  lis.c \
			  parsing.c \
			  push_swap_utils.c \
			  push_swap_utils2.c \
			  push.c \
			  b_reverse_rotate.c \
			  b_rotate.c \
			  b_stackpush.c  \
			  insertion_sort.c \
			  reverse_rotate.c \
			  rotate.c \
			  stackpush.c \

OBJS			= $(SRCS:.c=.o)

BOBJS			= $(BSRCS:.c=.o)

NAME			= push_swap

NAMECHECKER		= checker


CFLAGS			= -Wall -Wextra -Werror -g3

RM				= rm -f

CC				= gcc

AR				= ar rcs

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L.

$(NAMECHECKER):	$(BOBJS)
				$(CC) $(CFLAGS) $(BOBJS) -o $(NAMECHECKER) -L.

all:			$(NAME)

clean:
				$(RM) $(OBJS) $(BOBJS) 

fclean:			clean
				$(RM) $(NAME) $(NAMECHECKER)

re:				fclean all

bonus:			$(NAMECHECKER)

.PHONY:			all clean fclean c.o re bonus
