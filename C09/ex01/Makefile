NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c \
	 ./srcs/ft_strlen.c ./srcs/ft_swap.c
HFILES_DIR = ./includes/

OFILES = $(SRCS:.c=.o)

all: ${NAME}

${NAME}: ${OFILES}
	ar rc ${NAME} ${OFILES}

.c.o: 
	${CC} ${CFLAGS} -c -I ${HFILES_DIR} $< -o $@

clean:
	rm -rf ${OFILES}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
