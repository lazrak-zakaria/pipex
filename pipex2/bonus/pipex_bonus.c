#include "pipex_bonus.h"


void	first(char **av, char **env, int *pfd)
{
	int	fd;
	char	**v_av;
	char	*v_cmd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	//close(pfd[0]);
	dup2(fd, 0);
	dup2(pfd[1], 1);
	close(pfd[0]);
	v_av = ft_split(av[2], ' ');
	if (!v_av)
		exit(EXIT_FAILURE);
	if (!v_av[0])
		ft_print_error(v_av, NULL, "Error: command not found\n");
	if (v_av[0][0] == '/')
		ft_check_path(v_av, env);
	v_cmd = ft_get_cmd(env, v_av[0], v_av);
	//close(pfd[0]);
	execve(v_cmd, v_av, env);
	ft_mem_free(v_av);
	write (2, "Error : execve failed\n", 22);
	exit(EXIT_FAILURE);
}

void	second(int i, char **av, char **env, int *p_fd)
{
	char	**v_av;
	char	*v_cmd;


	dup2(p_fd[1], 1);
	close(p_fd[1]);
	close(p_fd[0]);
	v_av = ft_split(av[i], ' ');
	if (!v_av)
		exit(EXIT_FAILURE);
	if (!v_av[0])
		ft_print_error(v_av, NULL, "Error: command not found\n");
	if (v_av[0][0] == '/')
		ft_check_path(v_av, env);
	v_cmd = ft_get_cmd(env, v_av[0], v_av);
	//close(pfd[0]);
	execve(v_cmd, v_av, env);
	ft_mem_free(v_av);
	write (2, "Error : execve failed\n", 22);
	exit(EXIT_FAILURE);
}

void	last(char **av, char **env, int *pfd, int ac)
{
	int	fd;
	char	**v_av;
	char	*v_cmd;

	fd = open(av[ac - 1], O_RDONLY| O_CREAT, 0666);
	if (fd < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	//close(pfd[0]);
	dup2(fd, 1);
	dup2(pfd[0], 0);
	close (pfd[1]);
	v_av = ft_split(av[ac - 2], ' ');
	if (!v_av)
		exit(EXIT_FAILURE);
	if (!v_av[0])
		ft_print_error(v_av, NULL, "Error: command not found\n");
	if (v_av[0][0] == '/')
		ft_check_path(v_av, env);
	v_cmd = ft_get_cmd(env, v_av[0], v_av);
	//close(pfd[0]);
	execve(v_cmd, v_av, env);
	ft_mem_free(v_av);
	write (2, "Error : execve failed\n", 22);
	exit(EXIT_FAILURE);
}

void	third(int ac, char **av, char **env, int *pipe_fd)
{
	int		i;
	int		p_fd[2];
	int		pid;

	i = 3;
	while (i < ac - 2)
	{
		if (i == 3)
		{	dup2(pipe_fd[0], 0);   	 close(pipe_fd[0]); 	close(pipe_fd[1]); }
		else {   dup2(p_fd[0], 0);   close (p_fd[0]);  		close(p_fd[1]); }
		pipe(p_fd);
		pid = fork();
		if (!pid)
		{
			second(i, av, env, p_fd);
		}
		else
		{
			wait(NULL);
		}
		i++;
	}
	last(av, env, p_fd, ac);
}


void	ft_pipex_bonus(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	pid = fork();
	pipe(pipe_fd);
	if (pid < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (!pid)
		first(av, env, pipe_fd);
	else
	{
		wait(NULL);
		third(ac, av, env, pipe_fd);
	}
	
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
		return (0);
	ft_pipex_bonus(ac, av, env);
	return 0;
}