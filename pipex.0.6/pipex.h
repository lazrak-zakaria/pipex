/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:51:29 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/01 09:28:23 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
int		ft_cmp(char *a, char *b, int n);
char	**ft_split(char *s, char c);
char	**ft_mem_free(char **a);
int		ft_strlen(char *s);

void	ft_check_path(char **v_av, char **env);
char	*ft_get_cmd(char **env, char *cmd, char **v_av);

void	ft_print_error(char **a, char **b, char *c);
void	check_dup2(int *p_pipe, int std_fd_pipe);
void	ft_exec(char **av, char **env, int i);

#endif
