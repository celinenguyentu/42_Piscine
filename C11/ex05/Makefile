# -------------------------------- VARIABLES --------------------------------- #

NAME		=	do-op

INCLUDES	=	ft.h

SRCS		=	do_op.c			\
			ft_atoi.c		\
			ft_putstr.c		\
			ft_putnbr.c		\
			ft_strlen.c		\
			op.c

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

# ---------------------------------- RULES ----------------------------------- #

.c.o:
			$(CC) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(CC) -I $(INCLUDES) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
