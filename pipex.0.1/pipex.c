#include "pipex.h"

void	check_dup2(int fd, int std_fd, int *p_pipe, int std_fd_pipe)
{
	if ((dup2(fd, std_fd) < 0) || (dup2(p_pipe[std_fd_pipe], std_fd_pipe) < 0))
	{
		write(2, "dup2 Error \n", 12);
		exit(EXIT_FAILURE);
	}
}
/*

	// dup2(fd, 0);
	// dup2(pfd[1], 1);  c

	// dup2(fd, 1);
	// dup2(pfd[0], 0);   p


*/
void	ft_child(char **av, char **env, int *pfd)
{
	char	**v_av;
	char	*v_cmd;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(1);
	}
	close(pfd[0]);
	check_dup2(fd, 0, pfd, 1);
	v_av = ft_split(av[2], ' ');
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

void	ft_parent(char **av, char **env, int *pfd)
{
	char	**v_av;
	char	*v_cmd;
	int		fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
	{
		perror("Error");
		exit(1);
	}
	close(pfd[1]);
	check_dup2(fd, 1, pfd, 0);
	v_av = ft_split(av[3], ' ');
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

void	ft_pipex(char **av, char **env)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd))
	{
		perror("Error");
		exit (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (!pid)
		ft_child(av, env, pipe_fd);
	else
	{
		wait(0);
		ft_parent(av, env, pipe_fd);
	}
}

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
		return (0);
	ft_pipex(av, env);
	return (0);
}
