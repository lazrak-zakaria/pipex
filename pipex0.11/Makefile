# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:05:21 by zlazrak           #+#    #+#              #
#    Updated: 2023/01/10 11:35:10 by zlazrak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
	
OBJS = libft.o libft2.o pipex_utils2.o pipex_utils.o pipex.o 
BOBJS = w_libft_bonus.o w_libft2_bonus.o w_pipex_utils2_bonus.o w_pipex_utils_bonus.o w_here_doc_bonus.o w_pipex_bonus.o

ifndef BONUS
F_OBJ = ${OBJS}
else
F_OBJ = ${BOBJS}
endif

all : ${NAME}

${NAME} : ${F_OBJ}
	${CC} ${CFLAGS} ${F_OBJ} -o $@

 bonus : 
	@make BONUS=1

clean :
	rm -f ${OBJS} ${BOBJS}

fclean : clean
	rm -f ${NAME} ${B_NAME}

re : fclean all

.PHONY : clean fclean re all
