/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:51:37 by zlazrak           #+#    #+#             */
/*   Updated: 2023/01/01 14:51:04 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_path(char **v_av, char **env)
{
	if (!access(v_av[0], X_OK))
		execve(v_av[0], v_av, env);
	perror("Error");
	ft_mem_free(v_av);
	exit(127);
}

void	ft_print_error(char **a, char **b, char *c)
{
	ft_mem_free(a);
	ft_mem_free(b);
	if (*c)
		write(2, c, ft_strlen(c));
	exit(127);
}

char	*ft_get_access_cmd(char **v_arr)
{
	int		i;

	i = -1;
	while (v_arr[++i])
		if (!access(v_arr[i], X_OK))
			return (ft_strdup(v_arr[i]));
	return (NULL);
}

char	**ft_join_cmd(char **v_arr, char *cmd)
{
	int		i;
	char	*tmp;

	i = -1;
	cmd = ft_strjoin("/", cmd);
	if (!cmd)
		return (NULL);
	while (v_arr[++i])
	{
		tmp = ft_strjoin(v_arr[i], cmd);
		if (!tmp)
		{
			free (tmp);
			free (cmd);
			return (ft_mem_free(v_arr));
		}
		free(v_arr[i]);
		v_arr[i] = tmp;
	}
	free(cmd);
	return (v_arr);
}

char	*ft_get_cmd(char **env, char *cmd, char **v_av)
{
	char	*answer;
	char	**v_arr;
	int		i;

	i = -1;
	v_arr = NULL;
	while (env[++i] && !v_arr)
		if (ft_cmp(env[i], "PATH", 4))
			v_arr = ft_split(env[i] + 5, ':');
	if (!v_arr)
		ft_print_error(v_arr, v_av, "Error: PATH/command not found\n");
	if (!ft_join_cmd(v_arr, cmd))
		ft_print_error(v_arr, v_av, "");
	answer = ft_get_access_cmd(v_arr);
	if (!answer)
		ft_print_error(v_arr, v_av, "Error: command not found\n");
	return (answer);
}
