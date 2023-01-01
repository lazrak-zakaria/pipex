/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:49:16 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/01 09:39:47 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_first(char **av, char **env, int *pfd)
{
	int		fd;
	int		i;

	fd = here_doc(av, &i);
	if (fd < 0)
	{
		perror("Error");
		exit(1);
	}
	close(pfd[0]);
	check_dup2(fd, 0, pfd, 1);
	close(fd);
		ft_exec(av, env, i);
}

void	ft_second(int ac, char **av, char **env, int *pfd)
{
	t_arg	arg;
	pid_t	pid;
	int		i;

	i = 2;
	arg.env = env;
	arg.av = av;
	if (ft_cmp(av[1], "here_doc", 8))
		i = 3;
	while (++i < ac - 1)
	{
		pipe(pfd);
		pid = fork();
		if (!pid)
		{
			ft_third(ac, &arg, pfd, i);
		}
		else
		{
			wait(0);
			dup2(pfd[0], 0);
			close(pfd[0]);
			close(pfd[1]); //why because ine thne next fork i will read from the pipe  
		}
	}
}

void	ft_third(int ac, t_arg *arg, int*pfd, int i)
{
	ft_final_cmd(ac, arg->av, pfd, i);
	if (dup2(pfd[1], 1) < 0)
		ft_print_error(NULL, NULL, "Error dup\n");
	close(pfd[0]);
	close(pfd[1]);

	ft_exec(arg->av, arg->env, i);
}

void	ft_pipex_bonus(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		fd;

	pipe(pipe_fd);
	pid = fork();
	if (pid < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (!pid)
		ft_first(av, env, pipe_fd);
	else
	{
		wait(NULL);
		if (ft_cmp(av[1], "here_doc", 8))
			unlink("here_doc");
		dup2(pipe_fd[0], 0);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		ft_second(ac, av, env, pipe_fd);
	}
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
		return (0);
	ft_pipex_bonus(ac, av, env);
	return (0);
}
