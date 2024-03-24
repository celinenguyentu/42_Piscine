NAME = ft_tail

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_tail.c libft.c suffix.c utils.c
HFILES = ft.h

OFILES = $(SRCS:.c=.o)

all: ${NAME}

${NAME}: ${OFILES}
	${CC} -I ${HFILES} -o ${NAME} ${OFILES}

.c.o: 
	${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

clean:
	rm -f ${OFILES}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
