/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:51:21 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/21 10:44:31 by zlazrak          ###   ########.fr       */
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
	check_dup2(pfd, 1);
	close(pfd[0]);
	close(pfd[1]);
	ft_exec(av, env, 2);
	exit(EXIT_FAILURE);
}

void	ft_child_2(char **av, char **env, int *pfd)
{
	int		fd;

	close(1);
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		ft_error();
	check_dup2(pfd, 0);
	close(pfd[0]);
	ft_exec(av, env, 3);
	exit(EXIT_FAILURE);
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
	close(pipe_fd[1]);
	pid = fork();
	if (pid < 0)
		ft_error();
	else if (!pid)
		ft_child_2(av, env, pipe_fd);
	close(pipe_fd[0]);
	wait(NULL);
	wait(NULL);
}

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
	{
		write(2, "the program must take 4 arguments\n", 34);
		return (0);
	}
	ft_pipex(av, env);
	return (0);
}
