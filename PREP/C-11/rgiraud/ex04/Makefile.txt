SRCS	= main.c operators.c useful.c

NAME	= do-op

OBJS	=  ${SRCS:.c=.o}

HEADERS	= header/

.c.o	:
		gcc -Wall -Wextra -Werror -g -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		gcc -Wall -Wextra -Werror -g -I ${HEADERS} ${OBJS} -o ${NAME}

all : ${NAME}


clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all