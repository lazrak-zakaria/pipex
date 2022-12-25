/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:06:47 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/25 16:06:56 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>


void	ft_process(int *pfd, char **e, char **av, int k);

void	pipex(char **av, char **e)
{
	int 	pipefds[2];
	pid_t	parent;

	pipe(pipefds); 	 //protect_later
	parent = fork(); //protect_later
	if (!parent)
		ft_process(pipefds, e, av, 1);
	else 
	{
		wait(0);
		ft_process(pipefds, e, av, 0);
	}
}

void	ft_process(int *pfd, char **e, char **av, int k)
{
	char	*cmd;
	char	**av2;
	int		i;
	int		fd;
	
	if (k)
	{	
		fd = open(av[1], O_RDWR | O_CREAT, 0777);
		close(pfd[0]);
		dup2(fd, 0);
		dup2(pfd[1], 1);
		av2 = ft_split(av[2], ' ');
	}
	else 
	{
		fd = open(av[4], O_RDWR | O_CREAT, 0777);
		close(pfd[1]);
		dup2(pfd[0], 0);
		dup2(fd, 1);
		av2 = ft_split(av[3], ' ');
	}
	cmd = ft_get_cmd_path(e, av2[0]);
	
	//protect cmd && av2
	execve(cmd, av2, e);
	/*if (!k)
	{printf("parent\n");}
	else printf("cho\n");*/
	
	
}

int main(int ac, char **av, char **env)
{
	int	fd[2];

	if (ac != 5)
		return 0;
	pipex(av, env);
	return 0;
}
