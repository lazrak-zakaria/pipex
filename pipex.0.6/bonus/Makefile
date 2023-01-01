NAME = pipex
CC = CC
CFLAGS = -Wall -Wextra -Werror

OBJS = libft.o libft2.o z_pipex_utils2_bonus.o z_pipex_utils_bonus.o z_here_doc_bonus.o pipex_bonus.o 

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

clean : 
	rm -f ${OBJS}
fclean : clean
	rm -f ${NAME}

re : fclean all