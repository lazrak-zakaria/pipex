#include "pipex.h"

void	check_dup2(int *p_pipe, int std_fd_pipe)
{
	if (dup2(p_pipe[std_fd_pipe], std_fd_pipe) < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}
/*

	// dup2(fd, 0);
	// dup2(pfd[1], 1);  c

	// dup2(fd, 1);
	// dup2(pfd[0], 0);   p


*/

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
	perror("Error")
	ft_mem_free(v_av);
	free(v_cmd);
}

void	ft_error()
{
	perror("Error");
	exit(EXIT_FAILURE);
}