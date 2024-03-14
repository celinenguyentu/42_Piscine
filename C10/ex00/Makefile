NAME = ft_display_file

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_display_file.c

OFILES = $(SRCS:.c=.o)

all: ${NAME}

${NAME}: ${OFILES}
	${CC} ${CFLAGS} ${OFILES} -o ${NAME}

.c.o: 
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OFILES}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
