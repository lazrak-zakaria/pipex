NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = libft.o libft2.o pipex_utils2.o pipex_utils.o pipex.o 
OBJS = z_libft.o z_libft2.o z_pipex_utils2_bonus.o z_pipex_utils_bonus.o z_here_doc_bonus.o z_pipex_bonus.o

all : ${NAME}

bonus : ${BOBJS}
	${CC} ${CFLAGS} ${BOBJS} -o ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

clean :
	rm -f ${OBJS} {BOBJS}
fclean : clean
	rm -f ${NAME}

re : fclean all
