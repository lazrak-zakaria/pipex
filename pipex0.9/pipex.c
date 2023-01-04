/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:51:21 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/04 13:23:28 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(char **av, char **env, int *pfd)
{
	int		fd;

	close(0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error();
	close(pfd[0]);
	check_dup2(pfd, 1);
	ft_exec(av, env, 2);
}


void	ft_parent(char **av, char **env, int *pfd)
{
	int		fd;

	close(1);
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		ft_error();
	close(pfd[1]);
	check_dup2(pfd, 0);
	ft_exec(av, env, 3);
}

void	ft_pipex(char **av, char **env)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd))
		ft_error();
	pid = fork();
	if (pid < 0)
		ft_error();
	else if (!pid)
		ft_child(av, env, pipe_fd);
	else
	{
		wait(NULL);
		close(pipe_fd[1]);
		pid = fork();
		if (pid < 0)
			ft_error();
		else if (!pid)
			ft_parent(av, env, pipe_fd);
		else
		{
			wait(NULL);
			close(pipe_fd[0]);
		}
	}
}

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
		return (0);
	ft_pipex(av, env);
	return (0);
}
