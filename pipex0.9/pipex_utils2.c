/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:04:39 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/05 12:04:41 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_dup2(int *p_pipe, int std_fd_pipe)
{
	if (dup2(p_pipe[std_fd_pipe], std_fd_pipe) < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
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
	perror("Error");
	ft_mem_free(v_av);
	free(v_cmd);
}

void	ft_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}
