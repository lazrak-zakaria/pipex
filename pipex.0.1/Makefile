NAME = pipex
CC = CC
CFLAGS = -Wall -Wextra -Werror

OBJS = libft.o libft2.o pipex_utils.o pipex.o 

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

clean : 
	rm -f ${OBJS}
fclean : clean
	rm -f ${NAME}

re : fclean all