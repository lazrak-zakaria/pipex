// #include <unistd.h>
// #include <stdio.h>
// #include <fcntl.h>
// #include <stdlib.h>
// #include "pipex_bonus.h"



// int ft_find(char *s, char c)
// {
// 	while(*s)
// 	{
// 		if (*s == c)
// 			return 1;
// 		s++;
// 	}
// 	return 0;
// }
// int	ft_terminal_to_file(int fd, char **av)
// {
// 	char	*limit;
// 	char	*tmp;
// 	int		b;
// 	char	*s;
// 	int		i;

// 	i = 0;

// 	limit = ft_strjoin(av[2], "\n");
// 	tmp = malloc(sizeof(char) * (ft_strlen(limit) + 1)); //
// 	s = "";
// 	b = read(0, tmp, ft_strlen(limit));
// 	while (b > 0)
// 	{
// 		tmp[b] = '\0';
// 		s = ft_strjoin(s, tmp);
// 		//write(2, s, ft_strlen(s));
// 		if (ft_find(s, '\n'))
// 		{
// 			if (ft_cmp(s, limit, ft_strlen(limit)))
// 				break;
// 			write(fd, s, ft_strlen(s));
// 			s = "";
// 		}
		
// 		b = read(0, tmp, ft_strlen(limit));
// 	}
// 	free(tmp);
// 	if (b < 0)
// 		return 0;
// 	return (1);
// }

// int main(int ac, char **av)
// {

// 	//ft_terminal_to_file(1, av);
// 	int fd = open("achraf.txt", O_CREAT | O_RDWR, 0666);
// 	unlink("achraf.txt");
// }