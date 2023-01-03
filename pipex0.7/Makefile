NAME = pipex
B_NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
B_P=1
B_o=2
all : ${NAME}
		
BOBJS = z_libft.o z_libft2.o z_pipex_utils2_bonus.o z_pipex_utils_bonus.o z_here_doc_bonus.o z_pipex_bonus.o
OBJS = libft.o libft2.o pipex_utils2.o pipex_utils.o pipex.o 


${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

# bonus : ${B_NAME} 

# ${B_NAME} : ${BOBJS}
# 	${CC} ${CFLAGS} ${BOBJS} -o $@
# ${NAME} : ${BOBJS}
# 	${CC} ${CFLAGS} ${BOBJS} -o $@

clean :
	rm -f ${OBJS} ${BOBJS}
fclean : clean
	rm -f ${NAME}

re : fclean all
.PHONY : bonus B_BONUS