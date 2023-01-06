# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:05:21 by zlazrak           #+#    #+#              #
#    Updated: 2023/01/05 12:05:23 by zlazrak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
B_NAME = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
		
BOBJS = w_libft.o w_libft2.o w_pipex_utils2_bonus.o w_pipex_utils_bonus.o w_here_doc_bonus.o w_pipex_bonus.o
OBJS = libft.o libft2.o pipex_utils2.o pipex_utils.o pipex.o 

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

 bonus : ${B_NAME} 

${B_NAME} : ${BOBJS}
	${CC} ${CFLAGS} ${BOBJS} -o ${B_NAME}

clean :
	rm -f ${OBJS} ${BOBJS}

fclean : clean
	rm -f ${NAME} ${B_NAME}

re : fclean all

.PHONY : clean fclean re all
