#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_arg
{
	char	**av;
	char	**env;
} t_arg;

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
int	ft_cmp(char *a, char *b, int n);
char	**ft_split(char *s, char c);
char	**ft_mem_free(char **a);
int	ft_strlen(char *s);
int ft_find(char *s, char c);

void	ft_check_path(char **v_av, char **env);
char	*ft_get_cmd(char **env, char *cmd, char **v_av);

void	ft_print_error(char **a, char **b, char *c);
void	last(char **av, char **env, int *pfd, int ac);

int	ft_stdin_to_file(int fd, char *limit);
int	ft_sub_s_to_f(int fd, char *limit, char *t, char *s);
