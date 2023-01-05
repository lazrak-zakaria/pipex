/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:50:10 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/01 09:38:13 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_dup2(int fd, int std_fd, int *p_pipe, int std_fd_pipe)
{
	if ((dup2(fd, std_fd) < 0) || (dup2(p_pipe[std_fd_pipe], std_fd_pipe) < 0))
	{
		write(2, "dup2 Error \n", 12);
		exit(EXIT_FAILURE);
	}
}

int	here_doc(char **av, int *i)
{
	int	fd;

	if (ft_cmp("here_doc", av[1], 8))
	{
		fd = open(av[1], O_RDWR | O_CREAT, 0666);
		if (!ft_stdin_to_file(fd, av[2]))
			exit(EXIT_FAILURE);
		*i = 3;
		close(fd);
	}
	else
		*i = 2;
	fd = open(av[1], O_RDONLY);
	return (fd);
}

void	ft_final_cmd(int ac, char **av, int *pfd, int i)
{
	if (i == ac - 2)
	{
		close(pfd[1]);
		if (ft_cmp(av[1], "here_doc", 8))
			pfd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
		else
			pfd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (pfd[1] < 0)
		{
			perror("Error");
			exit(1);
		}
	}
}


void	ft_exec(char **av, char **env, int i)
{
	char	**v_av;
	char	*v_cmd;

	v_av = ft_split(av[i], ' ');
	if (!v_av)
		exit(EXIT_FAILURE);
	if (!v_av[0])
		ft_print_error(v_av, NULL, "Error: command not found\n");
	if (v_av[0][0] == '/')
		ft_check_path(v_av, env);
	v_cmd = ft_get_cmd(env, v_av[0], v_av);
	execve(v_cmd, v_av, env);
	ft_mem_free(v_av);
	write (2, "Error : execve failed\n", 22);
}